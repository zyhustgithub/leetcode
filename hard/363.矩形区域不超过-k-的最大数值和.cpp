/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxNum = INT_MIN;

        for (int pos = 0; pos < cols; ++pos) {
            vector<int> dp(rows, 0);
            for (int col = pos; col < cols; ++col) {
                for (int row = 0; row < rows; ++row) {
                    dp[row] += matrix[row][col];
                }
                maxNum = max(maxNum, GetMaxNum(dp, k));
            }
        }
        return maxNum;
    }

    int GetMaxNum(vector<int> &dp, int k)
    {
        int maxNum = INT_MIN;
        int sum = 0;
        for (int n : dp) {
            if (sum >= 0) {
                sum += n;
            } else {
                sum = n;
            }
            if (sum == k) {
                return sum;
            }
            if (sum > maxNum) {
                maxNum = sum;
            }
        }
        if (maxNum <= k) {
            return maxNum;
        }
        maxNum = INT_MIN;
        for (int pre = 0; pre < dp.size(); ++pre) {
            sum = 0;
            for (int post = pre; post < dp.size(); ++post) {
                sum += dp[post];
                if (sum == k) {
                    return sum;
                }
                if ((sum < k) && (sum > maxNum)) {
                    maxNum = sum;
                }
            }
        }
        return maxNum;
    }
};
// @lc code=end

