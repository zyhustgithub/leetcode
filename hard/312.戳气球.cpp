/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int numSize = nums.size();
        vector<vector<int>> dp(numSize, vector<int>(numSize, 0));

        for (int len = 2; len < numSize; ++len) {
            for (int pos = 0; pos + len < numSize; ++pos) {
                int end = pos + len;
                for (int brk = pos + 1; brk < end; ++brk) {
                    dp[pos][end] = max(dp[pos][end], dp[pos][brk] +
                        nums[pos] * nums[brk] * nums[end] + dp[brk][end]);
                }
            }
        }
        return dp[0][numSize - 1];
    }
};
// @lc code=end

