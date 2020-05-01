/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        DFS(res, candidates, vec, 0, target);
        return res;
    }

    void DFS(vector<vector<int>> &res, vector<int> &candidates,
        vector<int> vec, int pos, int left)
    {
        if (left == 0) {
            res.push_back(vec);
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            if (left < candidates.at(i)) {
                return;
            }
            if ((i != pos) && (candidates[i] == candidates[i - 1])) {
                continue;
            }
            vec.push_back(candidates.at(i));
            DFS(res, candidates, vec, i + 1, left - candidates[i]);
            vec.pop_back();
        }
    }
};
// @lc code=end

