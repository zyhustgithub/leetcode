/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int curFuel = startFuel;
        int distance = 0;
        int res = 0;
        priority_queue<int> pq;

        for (int idx = 0; idx < stations.size(); ++idx) {
            curFuel -= (stations[idx][0] - distance);
            while (!pq.empty() && (curFuel < 0)) {
                curFuel += pq.top();
                pq.pop();
                ++res;
            }

            if (curFuel < 0) {
                return -1;
            }
            
            if (stations[idx][0] >= target) {
                return res;
            }

            pq.push(stations[idx][1]);
            distance = stations[idx][0];
        }

        while (!pq.empty() && (distance + curFuel < target)) {
            curFuel += pq.top();
            pq.pop();
            ++res;
        }

        return (distance + curFuel >= target) ? res : -1;
    }
};
// @lc code=end

