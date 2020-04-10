/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int vecSize = height.size();
        int left = 0;
        int right = vecSize - 1;
        int sum = 0;
        int lMax = 0;
        int rMax = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                (height[left] >= lMax) ? lMax = height[left] :
                sum += lMax - height[left];
                ++left;
            } else {
                (height[right] >= rMax) ? rMax = height[right] :
                sum += rMax - height[right];
                --right;
            }
        }
        return sum;
    }
};
// @lc code=end

