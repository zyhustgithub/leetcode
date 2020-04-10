/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            while ((nums[i] > 0) && (nums[i] < numsSize) &&
                (nums[i] != i + 1) && (nums[nums[i] - 1] != nums[i])) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return numsSize + 1;
    }
};
// @lc code=end

