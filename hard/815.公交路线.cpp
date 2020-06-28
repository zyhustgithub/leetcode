/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        int routesSize = routes.size();
        auto *us = new unordered_set<int>[routesSize]();
        unordered_map<int, vector<int>> states;

        for (int idx = 0; idx < routesSize; ++idx) {
            for (auto n : routes[idx]) {
                us[idx].insert(n);
            }
        }

        queue<pair<int, int>> start;
        unordered_set<int> end;
        unordered_set<int> visit;
        for (int idx = 0; idx < routes.size(); ++idx) {
            if (us[idx].count(S) > 0) {
                start.push({idx, 1});
                visit.insert(idx);
            }

            if (us[idx].count(T) > 0) {
                end.insert(idx);
            }
            for (int post = idx + 1; post < routes.size(); ++post) {
                if (IsInteravtive(routes[idx], us[post])) {
                    states[idx].push_back(post);
                    states[post].push_back(idx);
                    // cout << idx << " " << post << endl;
                }
            }
        }
        
        while (!start.empty()) {
            pair<int, int> tmp = start.front();
            start.pop();
            // cout << tmp.first << " " << tmp.second << endl;

            if (end.count(tmp.first) > 0) {
                return tmp.second;
            }

            for (auto n : states[tmp.first]) {
                if (visit.count(n) == 0) {
                    visit.insert(n);
                    // cout << n << "," << tmp.second + 1;
                    start.push({n, tmp.second + 1});
                }
            }
        }

        delete [] us;
        return -1;
    }

    bool IsInteravtive(vector<int> &vec, unordered_set<int> &uset)
    {
        for (auto n : vec) {
            if (uset.count(n) > 0) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

