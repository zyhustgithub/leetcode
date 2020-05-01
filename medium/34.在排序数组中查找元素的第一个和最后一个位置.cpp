/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        return vector<int>{FindPre(nums, target), FindPost(nums, target)};
    }

    int FindPre(vector<int> &nums, int target)
    {
        int pre = 0;
        int post = nums.size() - 1;
        int mid = (pre + post) / 2;
        bool isRes = false;
        while (pre <= post) {
            if (nums[mid] < target) {
                pre = mid + 1;
            } else {
                if (nums[mid] == target) {
                    isRes = true;
                }
                post = mid - 1;
            }
            mid = (pre + post) / 2;
        }
        return isRes ? pre : -1;
    }

    int FindPost(vector<int> &nums, int target)
    {
        int pre = 0;
        int post = nums.size() - 1;
        int mid = (pre + post) / 2;
        bool isRes = false;
        while (pre <= post) {
            if (nums[mid] > target) {
                post = mid - 1;
            } else {
                if (nums[mid] == target) {
                    isRes = true;
                }
                pre = mid + 1;
            }
            mid = (pre + post) / 2;
        }
        return isRes ? pre - 1 : -1;
    }
};
// @lc code=end

