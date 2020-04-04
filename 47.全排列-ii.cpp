/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<vector<int>>(1, nums);
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        }while(NextPath(nums));
        return res;
    }

    bool NextPath(vector<int> &nums)
    {
        int pos = nums.size() - 1;
        while((pos > 0) && (nums[pos] <= nums[pos - 1])) {
            --pos;
        }
        if (pos == 0) {
            return false;
        }
        int pre = pos - 1;
        while (pos < nums.size()) {
            if (nums[pos] <= nums[pre]) {
                break;
            }
            ++pos;
        }
        swap(nums[pre], nums[pos - 1]);
        reverse(nums.begin() + pre + 1, nums.end());
        return true;
    }
};
// @lc code=end

