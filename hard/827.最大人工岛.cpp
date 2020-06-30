/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <map>

using namespace std;

const vector<vector<int>> nextPos = {{1, 0, -1, 0}, {0, 1, 0, -1}};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int idx = 2;
        bool allOne = true;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    allOne = false;
                } else if (grid[row][col] == 1) {
                    DFS(grid, row, col, idx);
                    ++idx;
                }
            }
        }

        if (allOne) {
            return rows * cols;
        }

        int ans = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    int tmp = 1;
                    set<int> tmpSet;
                    for (int pos = 0; pos < nextPos[0].size(); ++pos) {
                        int nextRow = row + nextPos[0][pos];
                        int nextCol = col + nextPos[1][pos];
                        if (IsValide(nextRow, nextCol) && (grid[nextRow][nextCol] > 1)) {
                            tmpSet.insert(grid[nextRow][nextCol]);
                        }
                    }
                    for (auto n : tmpSet) {
                        tmp += mp[n];
                    }
                    ans = max(ans, tmp);
                }
            }
        }

        return ans;
    }

    void DFS(vector<vector<int>> &grid, int row, int col, int idx)
    {
        grid[row][col] = idx;
        ++mp[idx];
        visit.insert(row * cols + col);
        for (int pos = 0; pos < nextPos[0].size(); ++pos) {
            int nextRow = row + nextPos[0][pos];
            int nextCol = col + nextPos[1][pos];
            if (IsValide(nextRow, nextCol) && (grid[nextRow][nextCol] == 1) &&
            (visit.count(nextRow * cols + nextCol) == 0)) {
                DFS(grid, nextRow, nextCol, idx);
            }
        }
    }

    bool IsValide(int row, int col)
    {
        return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
    }

private:
    int rows;
    int cols;
    unordered_map<int, int> mp;
    unordered_set<int> visit;
};
// @lc code=end

