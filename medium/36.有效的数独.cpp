/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> xValid(9, vector<int>(9, 0));
        vector<vector<int>> yValid(9, vector<int>(9, 0));
        vector<vector<int>> zValid(9, vector<int>(9, 0));

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (!((board[row][col] >= '1') && (board[row][col] <= '9'))) {
                    continue;
                }
                if (++xValid[row][board[row][col] - '0' - 1] > 1) {
                    return false;
                }
                if (++yValid[board[row][col] - '0' - 1][col] > 1) {
                    return false;
                }
                if (++zValid[(row / 3) * 3 + col / 3][board[row][col] - '0' - 1] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

