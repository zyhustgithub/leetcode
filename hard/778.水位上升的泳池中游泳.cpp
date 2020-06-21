/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
struct Node {
    int row;
    int col;
    int val;
    bool operator<(const Node &obj) const
    {
        return val > obj.val;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        return Bfs(grid);
    }

    int Bfs(vector<vector<int>> &grid)
    {
        int res = 0;
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        priority_queue<Node, vector<Node>> pq;
        visit[0][0] = true;
        pq.push({0, 0, grid[0][0]});
        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            res = max(res, cur.val);
            if ((cur.row == rows - 1) && (cur.col == cols - 1)) {
                break;
            }
            for (int idx = 0; idx < next[0].size(); ++idx) {
                int nextRow = cur.row + next[0][idx];
                int nextCol = cur.col + next[1][idx];
                if (IsValid(nextRow, nextCol) && !visit[nextRow][nextCol]) {
                    visit[nextRow][nextCol] = true;
                    pq.push({nextRow, nextCol, grid[nextRow][nextCol]});
                }
            }
        }
        return res;
    }

    bool IsValid(int row, int col)
    {
        return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
    }

private:
    int rows;
    int cols;
    vector<vector<int>> next = {{1, 0, -1, 0}, {0, 1, 0, -1}};
};
// @lc code=end

