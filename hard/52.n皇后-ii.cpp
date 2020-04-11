/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
// class Solution {
// public:
//     int totalNQueens(int n) {
//         vector<bool> cols(n, true);
//         vector<bool> lVec(2 * n - 1, true);
//         vector<bool> rVec(2 * n - 1, true);
//         int ans = 0;
//         DFS(n, 0, cols, lVec, rVec, ans);
//         return ans;
//     }

//     void DFS(int n, int row, vector<bool> &cols, vector<bool> &lVec,
//         vector<bool> &rVec, int &ans)
//     {
//         if (row == n) {
//             ++ans;
//             return;
//         }

//         for (int col = 0; col < n; ++col) {
//             int ll = row + col;
//             int rr = row - col + n - 1;
//             if (cols[col] && lVec[ll] && rVec[rr]) {
//                 cols[col] = false;
//                 lVec[ll] = false;
//                 rVec[rr] = false;
//                 DFS(n, row + 1, cols, lVec, rVec, ans);

//                 cols[col] = true;
//                 lVec[ll] = true;
//                 rVec[rr] = true;
//             }
//         }
//     }
// };

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        DFS(n, 0, 0, 0, 0, ans);
        return ans;
    }

    void DFS(int n, int row, int cols, int lVec, int rVec, int &ans)
    {
        if (row == n) {
            ++ans;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (((1 & (cols >> col)) == 0) && ((1 & (lVec >> (row + col))) == 0) &&
                ((1 & (rVec >> (row - col + n - 1))) == 0)) {
                DFS(n, row + 1, cols | (1 << col), lVec | (1 << (row + col)),
                    rVec | (1 << (row - col + n - 1)), ans);
            }
        }
    }
};
// @lc code=end

