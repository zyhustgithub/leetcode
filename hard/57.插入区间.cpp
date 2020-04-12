/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int vecSize = intervals.size();
        if (vecSize == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int l = 0;
        int r = vecSize - 1;
        int mid = (l + r) / 2;
        while (l <= r) {
            if (intervals[mid][1] < newInterval[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            mid = (l + r) / 2;
        }
        if (l == vecSize) {
            intervals.push_back(newInterval);
            return intervals;
        }
        newInterval[0] = min(newInterval[0], intervals[l][0]);
        for (r = l; r < vecSize; ++r) {
            if (intervals[r][0] > newInterval[1]) {
                break;
            }
            newInterval[1] = max(intervals[r][1], newInterval[1]);
        }
        intervals.insert(intervals.begin() + r, newInterval);
        intervals.erase(intervals.begin() + l, intervals.begin() + r);

        return intervals;
    }
};
// @lc code=end

