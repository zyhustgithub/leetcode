/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int numSize = nums.size();
        vector<int> res;
        deque<int> dq;
        for (int pos = 0; pos < k - 1; ++pos) {
            Push(dq, nums[pos]);
        }

        for (int pos = k - 1; pos < numSize; ++pos) {
            Push(dq, nums[pos]);
            res.push_back(dq.front());
            Pop(dq, nums[pos - k + 1]);
        }

        return res;
    }

    void Push(deque<int> &dq, int num)
    {
        while (!dq.empty() && (dq.back() < num)) {
            dq.pop_back();
        }

        dq.push_back(num);
    }

    void Pop(deque<int> &dq, int num)
    {
        if (!dq.empty() && (dq.front() == num)) {
            dq.pop_front();
        }
    }
};
// @lc code=end

