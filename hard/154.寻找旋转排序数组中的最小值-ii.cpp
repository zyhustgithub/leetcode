/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int numSize = nums.size();
        int left = 0;
        int right = numSize - 1;
        int mid = (left + right) / 2;

        while (left < right) {
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                --right;
            }
            mid = (left + right) / 2;
        }

        return nums[left];
    }
};
// @lc code=end

