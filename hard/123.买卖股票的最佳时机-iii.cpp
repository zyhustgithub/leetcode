/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int vecSize = prices.size();
        int dp1_0 = 0;
        int dp1_1 = -0x3f3f3f;
        int dp2_0 = 0;
        int dp2_1 = -0x3f3f3f;
        for (int i = 1; i <= vecSize; ++i) {
            dp1_0 = max(dp1_0, dp1_1 + prices[i - 1]);
            dp1_1 = max(dp1_1, - prices[i - 1]);
            dp2_0 = max(dp2_0, dp2_1 + prices[i - 1]);
            dp2_1 = max(dp2_1, dp1_0 - prices[i - 1]);
        }

        return dp2_0;
    }
};
// @lc code=end

