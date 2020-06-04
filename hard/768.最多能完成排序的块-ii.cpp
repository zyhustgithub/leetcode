/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        stack<int> st;
        st.push(arr[0]);
        for (int idx = 1; idx < arr.size(); ++idx) {
            int topVal = st.top();
            if (arr[idx] >= topVal) {
                st.push(arr[idx]);
                continue;
            }
            while (!st.empty() && (st.top() > arr[idx])) {
                st.pop();
            }
            st.push(topVal);
        }

        return st.size();
    }
};
// @lc code=end

