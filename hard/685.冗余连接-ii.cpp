/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> indexs(edges.size(), 0);
        fp.resize(edges.size(), 0);
        for (auto &vec : edges) {
            ++indexs[vec[1] - 1];
        }

        for (int idx = indexs.size() - 1; idx >= 0; --idx) {
            if (indexs[edges[idx][1] - 1] == 2) {
                if (IsValid(edges, idx)) {
                    return edges[idx];
                }
            }
        }

        for (int idx = indexs.size() - 1; idx >= 0; --idx) {
            if (indexs[edges[idx][1] - 1] == 1) {
                if (IsValid(edges, idx)) {
                    return edges[idx];
                }
            }
        }

        return {};
    }

    int Find(int x)
    {
        if (x == fp[x]) {
            return x;
        }
        return (fp[x] = Find(fp[x]));
    }

    bool IsValid(vector<vector<int>>& edges, int idx)
    {
        for (int i = 0; i < edges.size(); ++i) {
            fp[i] = i;
        }

        int cnt = edges.size();
        for (int i = 0; i < edges.size(); ++i) {
            if (i == idx) {
                continue;
            }

            int parent1 = Find(edges[i][0] - 1);
            int parent2 = Find(edges[i][1] - 1);
            if (parent1 != parent2) {
                --cnt;
                fp[parent2] = parent1;
            }
        }

        return cnt == 1;
    }

private:
    vector<int> fp;
};
// @lc code=end

