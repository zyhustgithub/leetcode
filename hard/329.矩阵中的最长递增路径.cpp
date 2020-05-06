/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int nextRow[] = {-1, 0, 1, 0};
        int nextCol[] = {0, 1, 0, -1};

        vector<vector<int>> neibors(rows, vector<int>(cols, 0));
        vector<vector<int>> dp(rows, vector<int>(cols, 1));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                for (int pos = 0; pos < 4; ++pos) {
                    int tmpRow = row + nextRow[pos];
                    int tmpCol = col + nextCol[pos];
                    if ((tmpRow >= 0) && (tmpRow < rows) && (tmpCol >= 0) &&
                        (tmpCol < cols) && matrix[row][col] < matrix[tmpRow][tmpCol]) {
                        ++neibors[tmpRow][tmpCol];
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (neibors[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }
        int res = 1;
        while (!q.empty()) {
            pair<int, int> topPair = q.front();
            q.pop();
            int num = dp[topPair.first][topPair.second] + 1;
            for (int pos = 0; pos < 4; ++pos) {
                int tmpRow = topPair.first + nextRow[pos];
                int tmpCol = topPair.second + nextCol[pos];
                if ((tmpRow >= 0) && (tmpRow < rows) && (tmpCol >= 0) &&
                    (tmpCol < cols) && matrix[topPair.first][topPair.second] <
                    matrix[tmpRow][tmpCol]) {
                    dp[tmpRow][tmpCol] = (dp[tmpRow][tmpCol] < num) ?
                        num : dp[tmpRow][tmpCol];
                    if (dp[tmpRow][tmpCol] > res) {
                        res = dp[tmpRow][tmpCol];
                    }
                    --neibors[tmpRow][tmpCol];
                    if (neibors[tmpRow][tmpCol] == 0) {
                        q.push({tmpRow, tmpCol});
                    }
                }

            }
        }

        return res;
    }
};
// @lc code=end

