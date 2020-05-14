/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(states));
    }
};
// @lc code=end

