/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct Data {
    vector<Data *> val;
    string str;
    Data() : val(vector<Data *>(26, nullptr)), str("") {}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Data *root = TreeWord(words);
        vector<string> res;
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (root->val[board[row][col] - 'a'] == nullptr) {
                    continue;
                }
                DFS(board, res, root, row, col);
            }
        }
        return res;
    }

    void DFS(vector<vector<char>> &board, vector<string> &res,
        Data *root, int row, int col)
    {
        char ch = board[row][col];
        if ((ch == '.') || (root->val[ch - 'a'] == nullptr)) {
            return;
        }
        Data *next = root->val[ch - 'a'];
        if (next->str != "") {
            res.push_back(next->str);
            next->str = "";
        }

        board[row][col] = '.';
        if (row > 0) {
            DFS(board, res, next, row - 1, col);
        }
        if (col > 0) {
            DFS(board, res, next, row, col - 1);
        }
        if (row < board.size() - 1) {
            DFS(board, res, next, row + 1, col);
        }
        if (col < board[0].size() - 1) {
            DFS(board, res, next, row, col + 1);
        }
        board[row][col] = ch;
    }

    Data *TreeWord(vector<string>& words)
    {
        Data *root = new Data();
        for (string &word : words) {
            Data *cur = root;
            for (char ch : word) {
                if (cur->val[ch - 'a'] == nullptr) {
                    cur->val[ch - 'a'] = new Data();
                }
                cur = cur->val[ch - 'a'];
            }
            cur->str = word;
        }

        return root;
    }
};
// @lc code=end

