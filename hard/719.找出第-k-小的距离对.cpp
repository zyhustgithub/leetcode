/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& arrNums, int k) {
        nums = arrNums;
        sort(nums.begin(), nums.end());
        limit = k;
        int left = 0;
        int right = nums.back() - nums.front();

        while (left < right) {
            int mid = (left + right) / 2;
            if (Cmp(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool Cmp(int guessNum)
    {
        int count = 0;
        int left = 0;
        for (int idx = 1; idx < nums.size(); ++idx) {
            while (nums[idx] - nums[left] > guessNum) {
                ++left;
            }
            count += (idx - left);
        }

        return count >= limit;
    }

private:
    int limit;
    vector<int> nums;
};
// @lc code=end

