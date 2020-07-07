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
// #include <multiset>

using namespace std;

constexpr int MOD_NUM = 1000000007;

// class Solution {
// public:
//     int rectangleArea(vector<vector<int>>& rectangles) {
//         set<int> xPos;
//         set<int> yPos;
//         for (auto &rec : rectangles) {
//             xPos.insert(rec[0]);
//             xPos.insert(rec[2]);
//             yPos.insert(rec[1]);
//             yPos.insert(rec[3]);
//         }

//         unordered_map<int, int> xIdx;
//         unordered_map<int, int> yIdx;
//         unordered_map<int, int> xMp;
//         unordered_map<int, int> yMp;
//         int tmp = 0;
//         for (auto it = xPos.begin(); it != xPos.end(); ++it, ++tmp) {
//             // cout << *it << "," << tmp << " ";
//             xIdx[tmp] = *it;
//             xMp[*it] = tmp;
//         }
//         // cout << endl;
//         tmp = 0;
//         for (auto it = yPos.begin(); it != yPos.end(); ++it, ++tmp) {
//             // cout << *it << "," << tmp << " ";
//             yIdx[tmp] = *it;
//             yMp[*it] = tmp;
//         }

//         vector<vector<bool>> grid(xPos.size(), vector<bool>(yPos.size(), false));
//         for (auto &rec : rectangles) {
//             for (int x = xMp[rec[0]]; x < xMp[rec[2]]; ++x) {
//                 for (int y = yMp[rec[1]]; y < yMp[rec[3]]; ++y) {
//                     grid[x][y] = true;
//                 }
//             }
//         }

//         uint64_t ans = 0;

//         for (int idx = 0; idx < xPos.size(); ++idx) {
//             for (int pos = 0; pos < yPos.size(); ++pos) {
//                 if (grid[idx][pos]) {
//                     // cout << idx << " " << pos << endl;
//                     ans = (ans + (uint64_t)(xIdx[idx + 1] - xIdx[idx]) * (yIdx[pos + 1] - yIdx[pos])) % MOD_NUM;
//                 }
//             }
//         }

//         return ans;
//     }
// };

struct Node {
    int y;
    bool op;
    int x1;
    int x2;

    bool operator<(const Node &obj) const
    {
        return std::tie(y, op, x1, x2) < std::tie(obj.y, obj.op, obj.x1, obj.x2);
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        for (auto &rec : rectangles) {
            lines.insert({rec[1], true, rec[0], rec[2]});
            lines.insert({rec[3], false, rec[0], rec[2]});
        }

        int curY = lines.begin()->y;
        // cout << lines.size() << endl;
        uint64_t ans = 0;
        for (auto &line : lines) {
            // cout << line.x1 << " " << line.x2 << endl;
            ans = (ans + (uint64_t)Query() * (line.y - curY)) % MOD_NUM;
            if (line.op) {
                seen.insert({line.x1, line.x2});
            } else {
                seen.erase(seen.find({line.x1, line.x2}));
            }
            
            curY = line.y;
        }

        return ans;
    }

    int Query()
    {
        int dis = 0;
        int cur = -1;
        for (auto &pos : seen) {
            cur = max(pos.first, cur);
            dis += max(0, pos.second - cur);
            cur = max(cur, pos.second);
        }

        return dis;
    }

private:
    set<Node> lines;
    multiset<pair<int, int>> seen;
};
// @lc code=end

