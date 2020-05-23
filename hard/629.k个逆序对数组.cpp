/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

// @lc code=start
constexpr int MOD_SUM = 1000000007;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int idx = 1; idx < n; ++idx) {
            dp[idx][0] = 1;
            for (int num = 1; num <= k; ++num) {
                dp[idx][num] = (dp[idx - 1][num] + dp[idx][num - 1]) % MOD_SUM;
                if (num > idx) {
                    dp[idx][num] = (dp[idx][num] + MOD_SUM - dp[idx - 1][num - idx - 1]) %
                        MOD_SUM;
                }
            }
        }

        return dp[n - 1][k] % MOD_SUM;
    }
};
// @lc code=end

