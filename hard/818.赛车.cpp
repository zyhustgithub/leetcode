/*
 * @lc app=leetcode.cn id=818 lang=cpp
 *
 * [818] 赛车
 */

// @lc code=start
constexpr int MAX_LEN = 10001;
int dp[MAX_LEN];

class Solution {
public:
    int racecar(int target) {
        if (dp[target] > 0) {
            return dp[target];
        }

        int n = floor(log2(target)) + 1;
        if (target == (1 << n) - 1) {
            return (dp[target] = n);
        }

        dp[target] = n + 1 + racecar((1 << n) - 1 - target);

        for (int idx = 0; idx < n - 1; ++idx) {
            dp[target] = min(dp[target], n + idx + 1 + racecar(target - (1 << (n - 1)) + (1 << idx)));
        }

        return dp[target];
    }
};
// @lc code=end

