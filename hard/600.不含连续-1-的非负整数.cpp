/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
// class Solution {
// public:
//     int findIntegers(int num) {
//         return DFS(num, 0, 0, false);
//     }

//     int DFS(int num, int sum, int idx, bool pre)
//     {
//         if (sum > num) {
//             return 0;
//         }

//         if ((1 << idx) > num) {
//             return 1;
//         }

//         if (pre) {
//             return DFS(num, sum, idx + 1, false);
//         }

//         return DFS(num, sum, idx + 1, false) + DFS(num, sum + (1 << idx), idx + 1, true);
//     }
// };

class Solution {
public:
    int findIntegers(int num) {
        int intSize = sizeof(int) * 8;
        vector<int> dp(intSize, 0);
        dp[0] = 1;
        dp[1] = 2;

        for (int idx = 2; idx < intSize; ++idx) {
            dp[idx] = dp[idx - 1] + dp[idx - 2];
        }

        int pos = intSize - 2;
        cout << pos;
        bool pre = false;
        int sum = 0;
        while (pos >= 0) {
            if ((num & (1 << pos)) != 0) {
                sum += dp[pos];
                if (pre) {
                    return sum;
                }
                pre = true;
            } else {
                pre = false;
            }
            --pos;
        }

        return sum + 1;
    }
};
// @lc code=end

