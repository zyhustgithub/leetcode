/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int64_t, int>> dp(A.size());
        int res = 0;
        for (int post = 1; post < A.size(); ++post) {
            for (int pre = 0; pre < post; ++pre) {
                int64_t delta = (int64_t)A[post] - (int64_t)A[pre];
                int num = 0;
                if (dp[pre].count(delta)) {
                    num = dp[pre][delta];
                    res += num;
                }
                dp[post][delta] += num + 1;
            }
        }

        return res;
    }
};
// @lc code=end

