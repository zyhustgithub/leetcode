/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int nSize = row.size();
        vector<int> f(nSize, 0);
        for (int idx = 0; idx < nSize; idx += 2) {
            f[idx + 1] = f[idx] = idx;
        }

        for (int idx = 0; idx < nSize; idx += 2) {
            if (Find(row[idx + 1], f) != Find(row[idx], f)) {
                f[Find(row[idx + 1], f)] = Find(row[idx], f);
            }
        }

        int res = nSize / 2;

        for (auto n : f) {
            cout << n;
        }

        for (int idx = 0; idx < nSize; idx += 2) {
            if (idx == Find(f[idx + 1], f)) {
                --res;
            }
        }

        return res;
    }

    int Find(int x, vector<int> &f)
    {
        if (x == f[x]) {
            return x;
        }
        return (f[x] = Find(f[x], f));
    }
};
// @lc code=end

