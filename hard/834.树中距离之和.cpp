/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        for (auto &vec : edges) {
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }
        vector<int> count(N, 1);
        vector<int> ans(N, 0);
        std::function<void(int cur, int parent)> Dfs1 =
            [&] (int cur, int parent) mutable -> void {
            for (auto node : mp[cur]) {
                if (node != parent) {
                    Dfs1(node, cur);
                    count[cur] += count[node];
                    ans[cur] += ans[node] + count[node];
                }
            }
        };

        std::function<void(int cur, int parent)> Dfs2 =
            [&] (int cur, int parent) mutable -> void {
            for (auto node : mp[cur]) {
                if (node != parent) {
                    ans[node] = ans[cur] + (N - count[node]) - count[node];
                    Dfs2(node, cur);
                }
            }
        };

        Dfs1(0, -1);
        Dfs2(0, -1);
        return ans;
    }

private:
    unordered_map<int, vector<int>> mp;
};
// @lc code=end

