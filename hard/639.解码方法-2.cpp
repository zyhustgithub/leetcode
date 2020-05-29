/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 2
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        constexpr int MOD_NUM = 1000000007;
        int strSize = s.size();
        vector<long> dp(strSize + 1, 0);
        dp[0] = 1;
        dp[1] = (s.front() == '*') ? 9 : ((s.front() == '0') ? 0 : 1);
        for (int pos = 2; pos <= strSize; ++pos) {
            if (s[pos - 1] == '*') {
                dp[pos] = (9L * dp[pos - 1]) % MOD_NUM;
                if (s[pos - 2] == '*') {
                    dp[pos] = (dp[pos] + 15L * dp[pos - 2]) % MOD_NUM;
                } else if (s[pos - 2] == '1') {
                    dp[pos] = (dp[pos] + 9L * dp[pos - 2]) % MOD_NUM;
                } else if (s[pos - 2] == '2') {
                    dp[pos] = (dp[pos] + 6L * dp[pos - 2]) % MOD_NUM;
                }
            } else {
                dp[pos] = (s[pos - 1] == '0') ? 0 : dp[pos - 1];
                if (s[pos - 2] == '*') {
                    dp[pos] = (dp[pos] + dp[pos - 2] +
                        ((s[pos - 1] <= '6') ? dp[pos - 2] : 0)) % MOD_NUM;
                } else if (s[pos - 2] == '1') {
                    dp[pos] = (dp[pos] + dp[pos - 2]) % MOD_NUM;
                } else if (s[pos - 2] == '2') {
                    dp[pos] = (dp[pos] + ((s[pos - 1] <= '6') ? dp[pos - 2] : 0)) % MOD_NUM;
                }
            }
        }

        return dp[strSize];
    }
};
// @lc code=end

