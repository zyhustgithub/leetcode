/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
// 动态规划
// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty()) {
//             return 0;
//         }
//         int xSize = matrix.size();
//         int ySize = matrix[0].size();
//         vector<vector<vector<int>>> dp(xSize,
//             vector<vector<int>>(ySize, vector<int>(3, 0)));
//         int row, col;
//         int maxRes = 0;
//         for (row = 0; row < xSize; ++row) {
//             for (col = 0; col < ySize; ++col) {
//                 if (matrix[row][col] == '0'){
//                     continue;
//                 }
//                 if ((row == 0) && (col == 0)) {
//                     dp[row][col] = {1, 1, 1};
//                 } else if (row == 0) {
//                     dp[row][col][0] = dp[row][col - 1][0] + 1;
//                     dp[row][col][1] = 1;
//                     dp[row][col][2] = dp[row][col - 1][2] + 1;
//                 } else if (col == 0) {
//                     dp[row][col][0] = 1;
//                     dp[row][col][1] = dp[row - 1][col][1] + 1;
//                     dp[row][col][2] = dp[row - 1][col][2] + 1;
//                 } else {
//                     dp[row][col][0] = dp[row][col - 1][0] + 1;
//                     dp[row][col][1] = dp[row - 1][col][1] + 1;
//                     MaxArea(dp, row, col);
//                 }
//                 if (maxRes < dp[row][col][2]) {
//                     maxRes = dp[row][col][2];
//                 }
//             }
//         }
//         return maxRes;
//     }

//     void MaxArea(vector<vector<vector<int>>> &dp, int row, int col)
//     {
//         int minLine = dp[row][col][0];
//         for (int count = 0; count <= row; ++count) {
//             if (dp[row - count][col][0] == 0) {
//                 break;
//             }
//             minLine = min(minLine, dp[row - count][col][0]);
//             dp[row][col][2] = max(dp[row][col][2], (count + 1) *
//                 minLine);
//         }
//     }
// };

// 单调栈
class Solution {
public:
    void Show(vector<int> &vec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int xSize = matrix.size();
        if (xSize == 0) {
            return 0;
        }
        int ySize = matrix[0].size();
        vector<int> dp(ySize + 1, 0);
        int res = 0;

        for (int row = 0; row < xSize; ++row) {
            for (int col = 0; col < ySize; ++col) {
                if (matrix[row][col] == '0') {
                    dp[col] = 0;
                } else {
                    ++dp[col];
                }
            }
            // Show(dp);
            stack<int> s;
            int area = 0;
            for (int pos = 0; pos <= ySize; ++pos) {
                while (!s.empty() && (dp[pos] < dp[s.top()])) {
                    int val = s.top();
                    s.pop();
                    area = max(area, dp[val] *
                        (s.empty() ? pos : (pos - s.top() - 1)));
                }
                s.push(pos);
            }
            if (res < area) {
                res = area;
            }
        }
        return res;
    }
};
// @lc code=end

