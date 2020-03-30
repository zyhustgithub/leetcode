/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int pre = 0;
        int post = height.size() - 1;
        int max = 0;
        int tmp = 0;
        while (pre < post) {
            tmp = (post - pre) * min(height[pre], height[post]);
            max = (max < tmp) ? tmp : max;
            if (height[pre] < height[post]) {
                ++pre;
            } else {
                --post;
            }
        }
        return max;
    }
};
// @lc code=end

