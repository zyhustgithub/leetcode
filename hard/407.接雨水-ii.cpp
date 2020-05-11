/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
struct Data {
    int row;
    int col;
    int height;

    Data(int r, int c, int h) : row(r), col(c), height(h) {}
    bool operator<(const Data &obj) const
    {
        return height > obj.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        if ((rows <= 2) || (cols <= 2)) {
            return 0;
        }

        priority_queue<Data> pq;
        vector<vector<int>> visited(rows, vector<int>(cols, false));

        for (int col = 0; col < cols; ++col) {
            visited[0][col] = true;
            pq.push({0, col, heightMap[0][col]});
            visited[rows - 1][col] = true;
            pq.push({rows - 1, col, heightMap[rows - 1][col]});
        }

        for (int row = 1; row < rows - 1; ++row) {
            visited[row][0] = true;
            pq.push({row, 0, heightMap[row][0]});
            visited[row][cols - 1] = true;
            pq.push({row, cols - 1, heightMap[row][cols - 1]});
        }

        int step[][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
        int res = 0;
        while (!pq.empty()) {
            Data cur = pq.top();
            pq.pop();
            for (int pos = 0; pos < 4; ++pos) {
                int nextRow = cur.row + step[0][pos];
                int nextCol = cur.col + step[1][pos];
                if ((nextRow >= 0) && (nextRow < rows) && (nextCol >= 0) &&
                    (nextCol < cols) && (!visited[nextRow][nextCol])) {
                    visited[nextRow][nextCol] = true;
                    if (heightMap[nextRow][nextCol] < cur.height) {
                        res += cur.height - heightMap[nextRow][nextCol];
                    }
                    heightMap[nextRow][nextCol] = max(heightMap[nextRow][nextCol],
                        cur.height);
                    pq.push({nextRow, nextCol, heightMap[nextRow][nextCol]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

