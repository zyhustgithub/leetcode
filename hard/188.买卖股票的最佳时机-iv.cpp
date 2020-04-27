/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int days = prices.size();
//         if (days < 2) {
//             return 0;
//         }
//         if (k >= (days / 2)) {
//             return Sum(prices);
//         }
        
//         vector<vector<vector<int>>> dp(days,
//             vector<vector<int>>(k + 1, vector<int>(2, 0)));

//         for (int idx = 1; idx <= k; ++idx) {
//             dp[0][idx][1] = -prices[0];
//         }

//         for (int day = 1; day < days; ++day) {
//             for (int exNum = 1; exNum <= k; ++exNum) {
//                     dp[day][exNum][0] = max(dp[day - 1][exNum][0],
//                         dp[day - 1][exNum][1] + prices[day]);
//                     dp[day][exNum][1] = max(dp[day - 1][exNum][1],
//                         dp[day - 1][exNum - 1][0] - prices[day]);
//             }
//         }

//         return dp[days - 1][k][0];
//     }

//     int Sum(vector<int> &prices)
//     {
//         int sum = 0;
//         for (int pos = 1; pos < prices.size(); ++pos) {
//             if (prices[pos] > prices[pos - 1]) {
//                 sum += (prices[pos] - prices[pos - 1]);
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if (days < 2) {
            return 0;
        }
        if (k >= (days / 2)) {
            return Sum(prices);
        }
        
        vector<int> dp(k + 1, 0);
        vector<int> hp(k + 1, -prices[0]);

        for (int day = 1; day < days; ++day) {
            for (int exNum = 1; exNum <= k; ++exNum) {
                    hp[exNum] = max(hp[exNum], dp[exNum - 1] -
                        prices[day]);
                    dp[exNum] = max(dp[exNum], prices[day] +
                        hp[exNum]);
            }
        }

        return dp[k];
    }

    int Sum(vector<int> &prices)
    {
        int sum = 0;
        for (int pos = 1; pos < prices.size(); ++pos) {
            if (prices[pos] > prices[pos - 1]) {
                sum += (prices[pos] - prices[pos - 1]);
            }
        }
        return sum;
    }
};
// @lc code=end

