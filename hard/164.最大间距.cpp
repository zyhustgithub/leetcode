/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int numSize = nums.size();
        if (numSize < 2) {
            return 0;
        }
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        int barrelSize = max(1, (maxNum - minNum) / (numSize - 1));
        int barrelNum = (maxNum - minNum) / barrelSize + 1;

        map<int, pair<int, int>> dp;

        for (int pos = 0; pos < numSize; ++pos) {
            int idx = (nums[pos] - minNum) / barrelSize;
            if (dp.count(idx)) {
                dp[idx].first = (nums[pos] < dp[idx].first) ?
                    nums[pos] : dp[idx].first;
                dp[idx].second = (nums[pos] > dp[idx].second) ?
                    nums[pos] : dp[idx].second;
            } else {
                dp[idx].first = dp[idx].second = nums[pos];
            }
        }

        int res = 0;
        int preMaxNum = minNum;
        for (auto &it : dp) {
            res = (res < (it.second.first - preMaxNum)) ?
                it.second.first - preMaxNum : res;
            preMaxNum = it.second.second;
        }

        return res;
    }
};
// @lc code=end

