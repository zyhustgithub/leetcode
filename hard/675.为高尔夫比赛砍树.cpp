/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
struct Data {
    int row;
    int col;
    int val;

    bool operator<(const Data &obj) const
    {
        return val > obj.val;
    }
};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<Data> pq;
        for (int row = 0; row < forest.size(); ++row) {
            for (int col = 0; col < forest[0].size(); ++col) {
                if (forest[row][col] > 1) {
                    pq.push({row, col, forest[row][col]});
                }
            }
        }

        int ans = 0;
        int startRow = 0;
        int startCol = 0;
        while (!pq.empty()) {
            int dstRow = pq.top().row;
            int dstCol = pq.top().col;
            pq.pop();
            int steps = BFS(forest, startRow, startCol, dstRow, dstCol);
            if (steps == -1) {
                return -1;
            }
            ans += steps;
            startRow = dstRow;
            startCol = dstCol;
        }

        return ans;
    }

    int BFS(vector<vector<int>> forest, int startRow, int startCol, int dstRow, int dstCol)
    {
        queue<Data> q;
        q.push({startRow, startCol, 0});
        forest[startRow][startCol] = 0;
        while (!q.empty()) {
            int row = q.front().row;
            int col = q.front().col;
            int steps = q.front().val;
            q.pop();
            if ((row == dstRow) && (col == dstCol)) {
                return steps;
            }

            for (int idx = 0; idx < 4; ++idx) {
                int nextRow = row + next[0][idx];
                int nextCol = col + next[1][idx];
                if (IsValid(forest, nextRow, nextCol)) {
                    forest[nextRow][nextCol] = 0;
                    q.push({nextRow, nextCol, steps + 1});
                }
            }
        }

        return -1;
    }

    bool IsValid(vector<vector<int>>& forest, int row, int col) {
        if ((row >= 0) && (row < forest.size()) && (col >= 0) && (col < forest[0].size()) &&
            forest[row][col] >= 1) {
            return true;
        }
        return false;
    }

    int Dijskra(vector<vector<int>> forest, int startRow, int startCol, int dstRow, int dstCol)
    {
        // ...
        return -1;
    }

private:
    vector<vector<int>> next = {{1, 0, -1, 0}, {0, 1, 0, -1}};
};
// @lc code=end

