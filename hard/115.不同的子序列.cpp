/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int sSize = s.size();
//         int tSize = t.size();
//         vector<vector<unsigned long>> dp(sSize + 1, vector<unsigned long>(tSize + 1, 0));
        
//         for (int row = 0; row <= sSize; ++row) {
//             dp[row][0] = 1;
//         }

//         for (int row = 1; row <= sSize; ++row) {
//             for (int col = 1; col <= min(row, tSize); ++col) {
//                 if (s[row - 1] == t[col - 1]) {
//                     dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
//                 } else {
//                     dp[row][col] = dp[row -1][col];
//                 }
//             }
//         }

//         return dp[sSize][tSize];
//     }
// };

class Solution {
public:
    int numDistinct(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        vector<unsigned long> dp(tSize + 1, 0);
        dp[0] = 1;

        for (int row = 1; row <= sSize; ++row) {
            for (int col = min(row, tSize); col >= 1; --col) {
                if (s[row - 1] == t[col - 1]) {
                    dp[col] = dp[col - 1] + dp[col];
                } else {
                    dp[col] = dp[col];
                }
            }
        }

        return dp[tSize];
    }
};
// @lc code=end

