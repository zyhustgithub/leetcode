/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        unsigned int xorNum = 0;
        for (auto n : nums) {
            xorNum ^= n;
        }

        return (xorNum == 0) || (nums.size() % 2 == 0);
    }
};
// @lc code=end

