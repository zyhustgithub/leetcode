/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [] (const vector<int> &a,
            const vector<int> &b) { return ((a[0] < b[0]) ||
                ((a[0] == b[0]) && (a[1] > b[1]))); });
        vector<int> dp;
        for (auto &env : envelopes) {
            int idx = lower_bound(dp.begin(), dp.end(), env[1]) - dp.begin();
            if (idx == dp.size()) {
                dp.push_back(env[1]);
            } else {
                dp[idx] = env[1];
            }
        }
        return dp.size();
    }
};
// @lc code=end

