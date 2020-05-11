/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        unsigned int sum = 0;
        int maxNum = INT_MIN;
        for (int num: nums) {
            sum += num;
            if (maxNum < num) {
                maxNum = num;
            }
        }

        unsigned int left = maxNum;
        unsigned int right = sum;
        unsigned int mid = left + (right - left) / 2;
        while (left < right) {
            if (CanSplit(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }
        return left;
    }

    bool CanSplit(vector<int> &nums, int m, unsigned int mid)
    {
        unsigned int curSum = 0;
        for (int num: nums) {
            if (curSum + num > mid) {
                --m;
                if (m <=0 ) {
                    return false;
                }
                curSum = num;
            } else {
                curSum += num;
            }
        }
        return true;
    }
};
// @lc code=end

