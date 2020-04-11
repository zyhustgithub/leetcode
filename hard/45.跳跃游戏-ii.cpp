/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int maxPos = 0;
        int steps = 0;
        for (int i = 0; i < nums.size() - 1; ++i) { // 理解小于nums.size() - 1很重要
            maxPos = (nums[i] + i > maxPos) ? nums[i] + i : maxPos;
            if (i == end) {
                end = maxPos;
                ++steps;    
            }
        }
        return steps;
    }
};
// @lc code=end

