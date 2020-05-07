/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

// @lc code=start
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4) {
            return false;
        }

        for (int pos = 3; pos < x.size(); ++pos) {
            if ((pos >= 3) && (x[pos] >= x[pos - 2]) && (x[pos - 1] <= x[pos - 3])) {
                return true;
            }

            if ((pos >= 4) && (x[pos] + x[pos - 4] >= x[pos - 2]) &&
                (x[pos - 1] == x[pos - 3])) {
                return true;
            }

            if ((pos >= 5) && (x[pos] + x[pos - 4] >= x[pos - 2]) &&
                (x[pos - 1] < x[pos - 3]) && (x[pos - 1] + x[pos - 5] >= x[pos - 3]) &&
                (x[pos - 2]) > x[pos - 4]) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

