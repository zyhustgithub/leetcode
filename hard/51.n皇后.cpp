/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> rec(n, string(n, '.'));
        vector<bool> cols(n, true);
        vector<bool> lVec(2 * n - 1, true);
        vector<bool> rVec(2 * n - 1, true);
        DFS(n, 0, cols, lVec, rVec, ans, rec);
        return ans;
    }

    void DFS(int n, int row, vector<bool> &cols, vector<bool> &lVec,
        vector<bool> &rVec, vector<vector<string>> &ans, vector<string> &rec)
    {
        if (row == n) {
            ans.push_back(rec);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int ll = row + col;
            int rr = row - col + n - 1;
            if (cols[col] && lVec[ll] && rVec[rr]) {
                cols[col] = false;
                lVec[ll] = false;
                rVec[rr] = false;
                rec[row][col] = 'Q';
                DFS(n, row + 1, cols, lVec, rVec, ans, rec);

                rec[row][col] = '.';
                cols[col] = true;
                lVec[ll] = true;
                rVec[rr] = true;
            }
        }
    }
};
// @lc code=end

