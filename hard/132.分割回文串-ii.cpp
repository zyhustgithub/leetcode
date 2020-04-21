/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
// class Solution {
// public:
//     int minCut(string s) {
//         int sSize = s.size();
//         vector<int> dp(sSize + 1, 0);

//         for (int i = 0; i <= sSize; ++i) {
//             dp[i] = i - 1;
//         }
        
//         for (int i = 1; i <= sSize; ++i) {
//             dp[i] = min(dp[i], dp[i - 1] + 1);

//             if (i == sSize) {
//                 break;
//             }

//             int start = i;
//             int end = i + 1;

//             while ((start >= 1) && (end <= sSize) &&
//                 (s[start - 1] == s[end - 1])) {
//                 dp[end] = min(dp[end], dp[start - 1] + 1);
//                 --start;
//                 ++end;
//             }

//             start = i - 1;
//             end = i + 1;
//             while ((start >= 1) && (end <= sSize) &&
//                 (s[start - 1] == s[end - 1])) {
//                 dp[end] = min(dp[end], dp[start - 1] + 1);
//                 --start;
//                 ++end;
//             }
//         }

//         return dp[sSize];
//     }
// };

class Solution {
public:
    int minCut(string s) {
        int sSize = s.size();
        vector<int> dp(sSize + 1, 0);

        for (int i = 0; i <= sSize; ++i) {
            dp[i] = i - 1;
        }
        
        vector<vector<bool>> bst(sSize, vector<bool>(sSize, false));

        for (int i = 0; i < sSize; ++i) {
            for (int j = 0; j <= i; ++j) {
                if ((s[j] == s[i]) && (((i - j) <= 2) ||
                    bst[j + 1][i - 1])) {
                    bst[j][i] = true;
                }
            }
        }

        for (int i = 1; i <= sSize; ++i) {
            if (bst[0][i - 1]) {
                dp[i] = 0;
                continue;
            }

            for (int j = 1; j <= i; ++j) {
                if (bst[j - 1][i - 1]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[sSize];
    }
};
// @lc code=end

