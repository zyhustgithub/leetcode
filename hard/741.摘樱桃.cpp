/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

// @lc code=start
constexpr int CAN_NOT = -0x3f3f3f;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int gridSize = grid.size();
        vector<vector<int>> dp(gridSize + 1, vector<int>(gridSize + 1, CAN_NOT));
        dp[gridSize - 1][gridSize - 1] = grid[gridSize - 1][gridSize - 1];

        int diagonalLines = 2 * gridSize - 3;

        for (int pos = diagonalLines; pos >= 0; --pos) {
            for (int rowa = max(0, pos - gridSize + 1); rowa <= min(gridSize - 1, pos); ++rowa) {
                int cola = pos - rowa;
                for (int rowb = rowa; rowb <= min(gridSize - 1, pos); ++rowb) {
                    int colb = pos - rowb;
                    if ((grid[rowa][cola] == -1) || (grid[rowb][colb] == -1)) {
                        dp[rowa][rowb] = CAN_NOT;
                    } else {
                        dp[rowa][rowb] = grid[rowa][cola] + (rowa != rowb) *
                            grid[rowb][colb] + max(max(dp[rowa + 1][rowb], dp[rowa][rowb + 1]),
                            max(dp[rowa + 1][rowb + 1], dp[rowa][rowb]));
                    }
                }
            }
        }

        return max(0, dp[0][0]);
    }
};
// @lc code=end

