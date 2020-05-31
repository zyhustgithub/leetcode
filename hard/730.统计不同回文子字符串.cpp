/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子字符串
 */

// @lc code=start
constexpr int MOD_NUM = 1000000007;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int idx = 0; idx < s.size(); ++idx) {
            dp[idx][idx] = 1;
        }

        for (int pre = s.size() - 2; pre >= 0; --pre) {
            for (int post = pre + 1; post < s.size(); ++post) {
                if (s[pre] != s[post]) {
                    dp[pre][post] = (dp[pre + 1][post] + dp[pre][post - 1]) % MOD_NUM +
                        (MOD_NUM - dp[pre + 1][post - 1]) % MOD_NUM;
                } else {
                    dp[pre][post] = (2 * dp[pre + 1][post - 1]) % MOD_NUM;
                    int left = pre + 1;
                    int right = post - 1;
                    while (left < post) {
                        if (s[left] == s[pre]) {
                            break;
                        }
                        ++left;
                    }

                    while (pre < right) {
                        if (s[right] == s[pre]) {
                            break;
                        }
                        --right;
                    }

                    if (left > right) {
                        dp[pre][post] += 2;
                    } else if (left == right) {
                        dp[pre][post] += 1;
                    } else {
                        dp[pre][post] += (MOD_NUM - dp[left + 1][right - 1]) % MOD_NUM;
                    }
                }

                dp[pre][post] = dp[pre][post] % MOD_NUM;
            }
        }

        return dp[0][s.size() - 1];
    }
};
// @lc code=end

