/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rowSize = dungeon.size();
        int colSize = dungeon[0].size();

        vector<vector<int>> dp(rowSize + 1, vector<int>(colSize + 1, 0x3f3f3f));
        dp[rowSize - 1][colSize] = 1;

        for (int row = rowSize - 1; row >= 0; --row) {
            for (int col = colSize - 1; col >= 0; --col) {
                dp[row][col] = max(1, min(dp[row][col + 1],
                dp[row + 1][col]) - dungeon[row][col]);
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

