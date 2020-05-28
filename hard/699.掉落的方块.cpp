/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        for (auto &vec : positions) {
            zip[vec[0]] = zip[vec[0] + vec[1] - 1] = 1;
        }

        int cnt = 1;
        for (auto &it : zip) {
            it.second = cnt++;
        }

        vector<int> res;
        for (auto &vec : positions) {
            int curVal = Query(zip[vec[0]], zip[vec[0] + vec[1] - 1], 1, 2 * positions.size(), 1);
            Update(zip[vec[0]], zip[vec[0] + vec[1] - 1], 1, 2 * positions.size(), 1, curVal + vec[1]);
            res.push_back(mp[1]);
        }

        return res;
    }

    void Update(int L, int R, int l, int r, int pos, int val)
    {
        if (l == r) {
            mp[pos] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (mid >= L) {
            Update(L, R, l, mid, pos << 1, val);
        }
        if (mid < R) {
            Update(L, R, mid + 1, r, (pos << 1) + 1, val);
        }

        mp[pos] = max(mp[pos << 1], mp[(pos << 1) + 1]);
    }

    int Query(int L, int R, int l, int r, int pos)
    {
        if ((l >= L) && (r <= R)) {
            return mp[pos];
        }

        int mid = l + (r - l) / 2;
        int res = 0;
        if (mid >= L) {
            res = Query(L, R, l, mid, pos << 1);
        }
        if (mid < R) {
            res = max(res, Query(L, R, mid + 1, r, (pos << 1) + 1));
        }
        return res;
    }

private:
    unordered_map<int, int> mp;
    map<int, int> zip;
};
// @lc code=end

