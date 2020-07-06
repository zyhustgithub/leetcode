/*
 * @lc app=leetcode.cn id=850 lang=cpp
 *
 * [850] 矩形面积 II
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

constexpr int MOD_NUM = 1000000007;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> xPos;
        set<int> yPos;
        for (auto &rec : rectangles) {
            xPos.insert(rec[0]);
            xPos.insert(rec[2]);
            yPos.insert(rec[1]);
            yPos.insert(rec[3]);
        }

        unordered_map<int, int> xIdx;
        unordered_map<int, int> yIdx;
        unordered_map<int, int> xMp;
        unordered_map<int, int> yMp;
        int tmp = 0;
        for (auto it = xPos.begin(); it != xPos.end(); ++it, ++tmp) {
            // cout << *it << "," << tmp << " ";
            xIdx[tmp] = *it;
            xMp[*it] = tmp;
        }
        // cout << endl;
        tmp = 0;
        for (auto it = yPos.begin(); it != yPos.end(); ++it, ++tmp) {
            // cout << *it << "," << tmp << " ";
            yIdx[tmp] = *it;
            yMp[*it] = tmp;
        }

        vector<vector<bool>> grid(xPos.size(), vector<bool>(yPos.size(), false));
        for (auto &rec : rectangles) {
            for (int x = xMp[rec[0]]; x < xMp[rec[2]]; ++x) {
                for (int y = yMp[rec[1]]; y < yMp[rec[3]]; ++y) {
                    grid[x][y] = true;
                }
            }
        }

        uint64_t ans = 0;

        for (int idx = 0; idx < xPos.size(); ++idx) {
            for (int pos = 0; pos < yPos.size(); ++pos) {
                if (grid[idx][pos]) {
                    // cout << idx << " " << pos << endl;
                    ans = (ans + (uint64_t)(xIdx[idx + 1] - xIdx[idx]) * (yIdx[pos + 1] - yIdx[pos])) % MOD_NUM;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

