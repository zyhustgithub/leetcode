/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        return FindNthMaxSum(nums, k, 3);
    }

    vector<int> FindNthMaxSum(vector<int>& nums, int k, int limit) {
        // 求 Kth 前缀和       
        vector<int> sums(nums.size() - k + 1, 0);
        for (int idx = 0; idx < k; ++idx) {
            sums[0] += nums[idx];
        }
        
        for (int idx = k; idx < nums.size(); ++idx) {
            sums[idx - k + 1] = sums[idx - k] + nums[idx] - nums[idx - k];
        }

        vector<vector<int>> dp(nums.size(), vector<int>(limit + 1, 0));
        vector<vector<int>> path(nums.size(), vector<int>(limit + 1, 0));
        dp[k - 1][1] = sums[0];
        path[k - 1][1] = k - 1;
        for (int idx = k; idx < nums.size(); ++idx) {
            for (int pos = 1; pos <= limit; ++pos) {
                dp[idx][pos] = dp[idx - 1][pos];
                path[idx][pos] = path[idx - 1][pos];
                if (dp[idx - k][pos - 1] + sums[idx - k + 1] > dp[idx][pos]) {
                    dp[idx][pos] = dp[idx - k][pos - 1] + sums[idx - k + 1];
                    path[idx][pos] = idx;
                }
            }
        }

        vector<int> res;
        int pathNum = limit;
        int insPos = nums.size() - 1;
        while (pathNum) {
            int tmp = path[insPos][pathNum];
            res.insert(res.begin(), tmp - k + 1);
            insPos = tmp - k;
            --pathNum;
        }

        return res;
    }
};
// @lc code=end

