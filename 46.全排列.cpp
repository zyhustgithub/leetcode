/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        vector<bool> used(nums.size(), false);
        DFS(res, nums, vec, used);
        return res;
    }

    void DFS(vector<vector<int>> &res, vector<int> &nums,
        vector<int> vec, vector<bool> used)
    {
        if (nums.size() == vec.size()) {
            res.push_back(vec);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            vec.push_back(nums[i]);
            used[i] = true;
            DFS(res, nums, vec, used);
            vec.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

