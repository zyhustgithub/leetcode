/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int numSize = nums.size();
        if (numSize < 3) {
            return 0;
        }
        int pre = 0;
        int post = 0;
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int pos = 0; pos < numSize -2; ++pos) {
            if (pos == 0 || (nums[pos] != nums[pos - 1])) {
                pre = pos + 1;
                post = numSize -1;
            }
            while (pre < post) {
                int tmp = nums[pre] + nums[post] + nums[pos];
                if (abs(ans - target) > abs(tmp - target)) {
                    ans = tmp;
                }
                if (tmp < target) {
                    ++pre;
                } else if (tmp > target) {
                    --post;
                } else {
                    return tmp;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

