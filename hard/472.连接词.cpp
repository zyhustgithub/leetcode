/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
struct Node {
    Node *next[26];
    bool isEnd;
    Node() : isEnd(false)
    {
        (void)memset(next, 0, sizeof(next));
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Node *root = new Node();

        for (auto &word: words) {
            Node *cur = root;
            for (auto ch: word) {
                if (cur->next[ch - 'a'] == nullptr) {
                    cur->next[ch - 'a'] = new Node();
                }
                cur = cur->next[ch - 'a'];
            }
            cur->isEnd = true;
        }

        vector<string> res;
        for (auto &word: words) {
            if (DFS(word, root, root, 0, 0)) {
                res.push_back(word);
            }
        }
        return res;
    }

    // bool DFS(string &word, Node *root, int count, int pos)
    // {
    //     Node *cur = root;
    //     for (int idx = pos; idx < word.size(); ++idx) {
    //         cur = cur->next[word[idx] - 'a'];
    //         if (cur == nullptr) {
    //             return false;
    //         }
    //         if (cur->isEnd) {
    //             if (idx == (word.size() - 1)) {
    //                 return (count >= 1);
    //             }
    //             if (DFS(word, root, count + 1, idx + 1)) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool DFS(string &word, Node *root, Node *cur, int count, int pos)
    {
        if (word.empty()) {
            return false;
        }

        if (cur->next[word[pos] - 'a'] == nullptr) {
            return false;
        }
        if (pos == word.size() - 1) {
            return (count >= 1) && (cur->next[word[pos] - 'a']->isEnd);
        }

        if (cur->next[word[pos] - 'a']->isEnd) {
            // if (DFS(word, root, root, count + 1, pos + 1)) {
            //     return true;
            // }
            return DFS(word, root, cur->next[word[pos] - 'a'], count, pos + 1) ||
                DFS(word, root, root, count + 1, pos + 1);
        }
        return DFS(word, root, cur->next[word[pos] - 'a'], count, pos + 1);
    }
};
// @lc code=end

