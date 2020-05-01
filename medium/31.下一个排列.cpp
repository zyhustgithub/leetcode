/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        size_t numsSize = nums.size();
        size_t pos = numsSize - 1;
        if (numsSize == 1) {
            return;
        }
        while ((pos > 0) && (nums[pos -1] >= nums[pos])) {
            --pos;
        }
        if (pos == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int tmpPos = pos; // 大于pos - 1位置数字的最小数字位置
        for (; tmpPos < numsSize; ++tmpPos) {
            if (nums[tmpPos] <= nums[pos - 1]) {
                break;
            }
        }
        
        nums[pos - 1] ^= nums[tmpPos - 1]; // 交换两个数
        nums[tmpPos - 1] ^= nums[pos - 1];
        nums[pos - 1] ^= nums[tmpPos - 1];

        reverse(nums.begin() + pos, nums.end());
    }
};
// @lc code=end

