/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vecRes;
        int numsSize = nums.size();
        if (numsSize < 3) {
            return vecRes;
        }
        sort(nums.begin(), nums.end());
        int pre = 0;
        int post = 0;
        for (int pos = 0; pos < numsSize; ++pos) {
            if (nums[pos] > 0) {
                break;
            }
            if (pos == 0 || nums[pos] != nums[pos - 1]) {
                pre = pos + 1;
                post = numsSize - 1;
            }
            while (pre < post) {
                if (nums[pre] + nums[post] < -nums[pos]) {
                    ++pre;
                } else if (nums[pre] + nums[post] == -nums[pos]) {
                    if ((pre == pos + 1) || nums[pre] != nums[pre - 1]) {
                        vector<int> tmp = {nums[pos], nums[pre], nums[post]};
                        vecRes.push_back(tmp);
                    }
                    ++pre;
                    --post;
                } else {
                    --post;
                }
            }
        }
        return vecRes;
    }
};
// @lc code=end

