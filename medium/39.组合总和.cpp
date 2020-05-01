/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> elem;
        DFS(res, candidates, elem, 0, target);
        return res;
    }

    void DFS(vector<vector<int>> &res, vector<int> &candidates,
        vector<int> elem, int start, int left)
    {
        if (left == 0) {
            if (!elem.empty()) {
                res.push_back(elem);
            }
            return;
        }
        for (int pos = start; pos < candidates.size(); ++pos) {
            if (candidates[pos] > left) {
                return;
            }
            elem.push_back(candidates[pos]);
            DFS(res, candidates, elem, pos, left - candidates[pos]);
            elem.pop_back();
        }
    }
};
// @lc code=end

