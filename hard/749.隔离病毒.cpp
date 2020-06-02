/*
 * @lc app=leetcode.cn id=749 lang=cpp
 *
 * [749] 隔离病毒
 */

// @lc code=start
struct Node {
    int row;
    int col;
    Node(int r, int c) : row(r), col(c) {}
    bool operator<(const Node &obj) const
    {
        if (row < obj.row) {
            return true;
        } else if (row == obj.row) {
            return col < obj.col;
        } else {
            return false;
        }
    }
};

int rect[][4] = {{0, -1, 0, 1}, {-1, 0, 1, 0}};

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int res = 0;
        while (true) {
            seen.clear();
            region.clear();
            frontier.clear();
            walls.clear();
            for (int num = 0; num < rows * cols; ++num) {
                int row = num / cols;
                int col = num % cols;
                if ((grid[row][col] == 1) && (seen.count(num) == 0)) {
                    region.push_back({});
                    frontier.push_back({});
                    walls.push_back(0);
                    DFS(grid, row, col);
                }
            }

            if (region.empty()) {
                break;
            }

            int maxIdx = 0;
            int numSize = 0;
            for (int i = 0; i < frontier.size(); ++i) {
                if (numSize < frontier[i].size()) {
                    maxIdx = i;
                    numSize = frontier[i].size();
                }
            }

            res += walls[maxIdx];

            for (int i = 0; i < region.size(); ++i) {
                if (i == maxIdx) {
                    for (int num : region[i]) {
                        grid[num / cols][num % cols] = -1;
                    }
                } else {
                    for (int num : region[i]) {
                        int orir = num / cols;
                        int oril = num % cols;
                        for (int idx = 0; idx < 4; ++idx) {
                            int r = orir + rect[0][idx];
                            int c = oril + rect[1][idx];
                            if (IsValid(r, c) && (grid[r][c] == 0)) {
                                grid[r][c] = 1;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }

    void DFS(vector<vector<int>> &grid, int row, int col)
    {
        int num = row * cols + col;
        if (seen.count(num) != 0) {
            return;
        }
        seen.insert(num);
        region.back().push_back(num);
        for (int idx = 0; idx < 4; ++idx) {
            int r = row + rect[0][idx];
            int c = col + rect[1][idx];
            if (IsValid(r, c)) {
                if (grid[r][c] == 1) {
                    DFS(grid, r, c);
                } else if (grid[r][c] == 0) {
                    frontier.back().insert(Node(r, c));
                    ++walls.back();
                }
            }
        }
    }

    bool IsValid(int row, int col)
    {
        if ((row >= 0) && (row < rows) && (col >= 0) && (col < cols)) {
            return true;
        }
        return false;
    }

private:
    unordered_set<int> seen;
    vector<vector<int>> region;
    vector<set<Node>> frontier;
    vector<int> walls;
    int rows;
    int cols;
};
// @lc code=end

