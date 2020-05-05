/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums{0};
        for (int pos = 0; pos < nums.size(); ++pos) {
            sums.push_back(sums.back() + nums[pos]);
        }
        return DoubleBreakDFS(sums, 0, sums.size() - 1, lower, upper);
    }

    int DoubleBreakDFS(vector<long> &sums, int left, int right, int lower,
        int upper)
    {
        if (left == right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int count = DoubleBreakDFS(sums, left, mid, lower, upper) +
            DoubleBreakDFS(sums, mid + 1, right, lower, upper);
        
        int lowNum = mid + 1;
        int upNum = mid + 1;
        for (int l = left; l <= mid; ++l) {
            while ((lowNum <= right) && (sums[lowNum] - sums[l]) < lower) {
                ++lowNum;
            }

            while ((upNum <= right) && (sums[upNum] - sums[l]) <= upper) {
                ++upNum;
            }

            count += upNum - lowNum;
        }

        inplace_merge(sums.begin() + left, sums.begin() + mid + 1,
            sums.begin() + right + 1);
        return count;
    }
};
// @lc code=end

