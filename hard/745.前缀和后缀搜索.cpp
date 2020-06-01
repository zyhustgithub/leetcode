/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
struct Node {
    Node *next[27];
    int weight = 0;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int wt = 0;
        root = new Node();
        for (auto &word : words) {
            for (int num = 0; num <= word.size(); ++num) {
                string tmp = word.substr(word.size() - num, num) + '#' + word;
                Node *cur = root;
                for (auto ch : tmp) {
                    int idx = (ch == '#') ? 26 : ch - 'a';
                    if (cur->next[idx] == nullptr) {
                        cur->next[idx] = new Node();
                    }
                    cur->next[idx]->weight = wt;
                    cur = cur->next[idx];
                }
            }
            ++wt;
        }
    }
    
    int f(string prefix, string suffix) {
        string patern =suffix + '#' + prefix;

        Node *cur = root;
        for (auto ch : patern) {
            int idx = (ch == '#') ? 26 : ch - 'a';
            if (cur->next[idx] == nullptr) {
                return -1;
            }
            cur = cur->next[idx];
        }
        return cur->weight;
    }

private:
    Node *root = nullptr;
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

