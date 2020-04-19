/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        CreateMap(unordered_set<string>(wordList.begin(), wordList.end()), beginWord,
            endWord);
        // Show(parentMap);
        vector<vector<string>> res;
        DFS(beginWord, vector<string>(), endWord, res);
        return res;
    }

    void Show(map<string, set<string>> &parentMap)
    {
        for (auto &v : parentMap) {
            cout << v.first << ":";
            for (auto &s : v.second) {
                cout << s << " ";
            }
            cout << endl;
        }
    }

    void DFS(string &beginWord, vector<string> path, string curStr,
        vector<vector<string>> &res)
    {
        path.push_back(curStr);
        if (curStr == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }

        for (auto &s : parentMap[curStr]) {
            DFS(beginWord, path, s, res);
        }
    }

    void CreateMap(unordered_set<string> wordList, string &beginWord,
        string &endWord)
    {
        unordered_set<string> nextSet;
        unordered_set<string> curSet{beginWord};

        for (; curSet.size() && parentMap.find(endWord) == parentMap.end();
            curSet = nextSet) {
            nextSet.clear();

            for (auto &s : curSet) {
                for (int pos = 0; pos < s.size(); ++pos) {
                    string tmp = s;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[pos] = c;
                        if (wordList.count(tmp) > 0) {
                            parentMap[tmp].insert(s);
                            nextSet.insert(tmp);
                        }
                    }
                }
            }

            for (auto &s : nextSet) {
                wordList.erase(s);
            }
        }
    }

    // void CreateMap(unordered_set<string> wordList, string &beginWord)
    // {
    //     queue<string> st;
    //     st.push(beginWord);
    //     depth[beginWord] = 1;

    //     while(!st.empty()) {
    //         string curStr = st.front();
    //         st.pop();

    //         for (int pos = 0; pos < curStr.size(); ++pos) {
    //             string tmp = curStr;
    //             for (char ch = 'a'; ch <= 'z'; ++ch) {
    //                 tmp[pos] = ch;
    //                 if (wordList.count(tmp) > 0) {
    //                     if (depth[tmp] == 0) {
    //                         depth[tmp] = depth[curStr] + 1;
    //                         parentMap[tmp].insert(curStr);
    //                         st.push(tmp);
    //                     } else if (depth[tmp] == depth[curStr] + 1) {
    //                         parentMap[tmp].insert(curStr);
    //                         st.push(tmp);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

private:
    unordered_map<string, int> depth;
    unordered_map<string, set<string>> parentMap;
};
// @lc code=end

