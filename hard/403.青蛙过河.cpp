/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
//         unordered_set<int> sp(stones.begin(), stones.end());
//         unordered_map<long long, bool> dp;
//         constexpr int MAX_STONES = 1100;

//         function<bool(int, int)> DFS = [&sp, &dp, MAX_STONES] (int dest, int step) -> bool
//         {
//             if ((sp.count(dest) == 0) || (step <= 0) || (step > dest)) {
//                 return false;
//             }
//             if ((dest == 1) && (step == 1)) {
//                 return true;
//             }

//             long long tmp = (dest >> 32) + step;
//             if (dp[tmp]) {
//                 return true;
//             }
//             if (DFS(dest - step, step - 1) || DFS(dest - step, step) ||
//                 DFS(dest - step, step + 1)) {
//                 return true;
//             }
//             dp[tmp] = true;
//         };

//         for (int pos = 1; pos < MAX_STONES; ++pos) {
//             if (DFS(stones.back(), pos)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<bool>> dp(stones.size(), vector<bool>(stones.size(), false));
        dp[0][0] = true;

        for (int pos = 1; pos < stones.size(); ++pos) {
            for (int idx = 0; idx < pos; ++idx) {
                int steps = stones[pos] - stones[idx];
                if (steps > stones.size() - 1) {
                    continue;
                }
                dp[pos][steps] = dp[idx][steps - 1] || dp[idx][steps];
                if (steps + 1 < stones.size()) {
                    dp[pos][steps] = dp[pos][steps] || dp[idx][steps + 1];
                }
                if ((pos == stones.size() - 1) && dp[pos][steps]) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

