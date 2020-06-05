/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> seen;
        string str;
        for (auto &vec : board) {
            for (auto n : vec) {
                str += n + '0';
            }
        }
        vector<vector<int>> near = {
            {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}
        };

        queue<string> q;
        q.push(str);
        seen.insert(str);
        int steps = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int idx = 0; idx < qSize; ++idx) {
                string topStr = q.front();
                q.pop();
                if (topStr == "123450") {
                    return steps;
                }

                int pos = topStr.find('0');
                for (auto n : near[pos]) {
                    string tmpStr = topStr;
                    tmpStr[pos] = tmpStr[n];
                    tmpStr[n] = '0';
                    // cout << tmpStr << endl;
                    if (seen.count(tmpStr) == 0) {
                        seen.insert(tmpStr);
                        q.push(tmpStr);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};
// @lc code=end

