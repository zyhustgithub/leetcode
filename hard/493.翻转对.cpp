/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
public:
    void Update(vector<int> &arrTree, int idx, int val)
    {
        while (idx > 0) {
            arrTree[idx] += val;
            idx -= (idx & (-idx));
        }
    }

    int GetNum(vector<int> &arrTree, int idx)
    {
        int res = 0;
        while (idx < arrTree.size()) {
            res += arrTree[idx];
            idx += (idx & (-idx));
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> sortNums(nums.begin(), nums.end());
        sort(sortNums.begin(), sortNums.end());
        vector<int> arrTree(nums.size() + 1, 0);
        int res = 0;

        for (int idx = 0; idx < nums.size(); ++idx) {
            res += GetNum(arrTree, lower_bound(sortNums.begin(), sortNums.end(),
                2LL * nums[idx] + 1) - sortNums.begin() + 1);
            Update(arrTree, lower_bound(sortNums.begin(), sortNums.end(),
                nums[idx]) - sortNums.begin() + 1, 1);
        }

        return res;
    }
};
// @lc code=end

