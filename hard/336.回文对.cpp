/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

// @lc code=start
struct Data {
    vector<Data *> next;
    vector<int> suffix;
    int index;

    Data() : index(-1)
    {
        next.resize(26, 0);
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Data *root = BuildTree(words);
        vector<vector<int>> res;
        for (int idx = 0; idx < words.size(); ++idx) {
            Data *cur = root;
            int pos = 0;
            for (; pos < words[idx].size(); ++pos) {
                if (IsPalindrome(words[idx].substr(pos)) && (cur->index != -1)) {
                    res.push_back({idx, cur->index});
                }
                int tmp = words[idx][pos] - 'a';
                cur = cur->next[tmp];
                if (cur == 0) {
                    break;
                }
            }

            if (pos == words[idx].size()) {
                for (int n : cur->suffix) {
                    if (n != idx) {
                        res.push_back({idx, n});
                    }
                }
            }
        }
        return res;
    }

    Data *BuildTree(vector<string> &words)
    {
        Data *root = new Data();

        for (int idx = 0; idx < words.size(); ++idx) {
            string word(words[idx]);
            reverse(word.begin(), word.end());

            if (IsPalindrome(word)) {
                root->suffix.push_back(idx);
            }
            Data *cur = root;
            for (int pos = 0; pos < word.size(); ++pos) {
                int ch = word[pos] - 'a';
                if (cur->next[ch] == 0) {
                    cur->next[ch] = new Data();
                }
                cur = cur->next[ch];
                if (IsPalindrome(word.substr(pos + 1))) {
                    cur->suffix.push_back(idx);
                }
            }
            cur->index = idx;
        }
        return root;
    }

    bool IsPalindrome(string str)
    {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end

