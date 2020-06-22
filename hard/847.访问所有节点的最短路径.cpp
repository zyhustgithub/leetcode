/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        set<pair<uint32_t, uint8_t>> visited;
        queue<pair<uint32_t, uint8_t>> curNodes;
        uint32_t graphSize = graph.size();

        if (graphSize < 2) {
            return 0;
        }

        for (int idx = 0; idx < graphSize; ++idx) {
            curNodes.push({(1 << idx), idx});
        }

        int steps = 0;
        for (; !curNodes.empty(); ++steps) {
            int stackSize = curNodes.size();
            while (stackSize--) {
                pair<uint32_t, uint8_t> tmp = curNodes.front();
                curNodes.pop();
                for (int pos : graph[tmp.second]) {
                    int val = tmp.first | (1 << pos);
                    if (val == ((1 << graphSize) - 1)) {
                        return steps + 1;
                    }
                    if (!visited.count({val, pos})) {
                        visited.insert({val, pos});
                        curNodes.push({val, pos});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

