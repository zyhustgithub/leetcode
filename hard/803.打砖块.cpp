/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        rows = grid.size();
        cols = grid[0].size();
        const int nums = rows * cols;
        bool *visit = new bool[nums]();
        f = vector<int>(nums, 0);
        size = vector<int>(nums, 1);

        for (int idx = 0; idx < nums; ++idx) {
            f[idx] = idx;
        }

        vector<vector<int>> bak(grid);
        for (auto &vec : hits) {
            grid[vec[0]][vec[1]] = 0;
        }
        for (int idx = 0; idx < nums; ++idx) {
            int row = idx / cols;
            int col = idx % cols;
            if (grid[row][col] == 0) {
                continue;
            }
            for (int pos = 0; pos < next[0].size(); ++pos) {
                int nextRow = row + next[0][pos];
                int nextCol = col + next[1][pos];
                if (IsValid(nextRow, nextCol) && (grid[nextRow][nextCol] != 0)) {
                    Union(idx, nextRow * cols + nextCol);
                }
            }
        }

        // Show();
        int preCnt = 0;
        for (int idx = 0; idx < cols; ++idx) {
            if (grid[0][idx] == 0) {
                continue;
            }
            if (!visit[Find(idx)]) {
                visit[Find(idx)] = true;
                preCnt += size[Find(idx)];
            }
        }

        vector<int> ans(hits.size(), 0);
        for (int hitPos = hits.size() - 1; hitPos >= 0; --hitPos) {
            vector<int> &vec = hits[hitPos];
            if (bak[vec[0]][vec[1]] == 0) {
                continue;
            }
            grid[vec[0]][vec[1]] = 1;
            for (int pos = 0; pos < next[0].size(); ++pos) {
                int nextRow = vec[0] + next[0][pos];
                int nextCol = vec[1] + next[1][pos];
                if (IsValid(nextRow, nextCol) && (grid[nextRow][nextCol] != 0)) {
                    Union(vec[0] * cols + vec[1], nextRow * cols + nextCol);
                }
            }
            int cnt = 0;
            (void)memset(visit, false, nums);
            for (int idx = 0; idx < cols; ++idx) {
                if (grid[0][idx] == 0) {
                    continue;
                }
                if (!visit[Find(idx)]) {
                    visit[Find(idx)] = true;
                    cnt += size[Find(idx)];
                }
            }
            ans[hitPos] = (cnt - preCnt - 1 == -1) ? 0 : (cnt - preCnt - 1);
            // Show();
            preCnt = cnt;
        }

        delete [] visit;
        return ans;
    }

    bool IsValid(int row, int col) {
        return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
    }

    void Show()
    {
        for (auto n : f) {
            cout << n << " ";
        }
        cout << endl;
        for (auto n : size) {
            cout << n << " ";
        }
        cout << endl;
    }

    int Find(int x)
    {
        if (x == f[x]) {
            return x;
        }
        return (f[x] = Find(f[x]));
    }

    void Union(int x, int y)
    {
        int p = Find(x);
        int q = Find(y);
        if (p != q) {
            size[p] += size[q];
            f[q] = p;
        }
    }

private:
    int rows = 0;
    int cols = 0;
    vector<int> f;
    vector<int> size;
    vector<vector<int>> next = {{1, 0, -1, 0}, {0, 1, 0, -1}};
};

// @lc code=end

