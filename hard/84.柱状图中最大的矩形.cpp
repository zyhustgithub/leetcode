/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int vecSize = heights.size();
        int maxArea = 0;
        stack<int> st;
        for (int pos = 0; pos < vecSize; ++pos) {
            while (!st.empty() && (heights[pos] < heights[st.top()])) {
                int cur = st.top();
                st.pop();
                maxArea = max(maxArea, heights[cur] *
                    (st.empty() ? pos : (pos - st.top() - 1)));
            }
            st.push(pos);
        }
        return maxArea;
    }
};
// @lc code=end

