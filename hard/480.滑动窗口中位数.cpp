/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return vector<double>(nums.begin(), nums.end());
        }

        priority_queue<int> lq;
        priority_queue<int, vector<int>, greater<int>> rq;
        unordered_map<int, int> mp;

        for (int idx = 0; idx < k; ++idx) {
            lq.push(nums[idx]);
        }

        for (int idx = 0; idx < k / 2; ++idx) {
            rq.push(lq.top());
            lq.pop();
        }

        vector<double> res;
        for (int pos = k; pos < nums.size(); ++pos) {
            res.push_back((k % 2 == 0) ? ((double)lq.top() + (double)rq.top()) * 0.5 :
                lq.top());

            int inNum = nums[pos];
            int outNum = nums[pos - k];
            ++mp[outNum];

            int balance = (outNum <= lq.top()) ? -1 : 1;
            if (inNum <= lq.top()) {
                lq.push(inNum);
                ++balance;
            } else {
                rq.push(inNum);
                --balance;
            }

            if (balance < 0) {
                lq.push(rq.top());
                rq.pop();
            }

            if (balance > 0) {
                rq.push(lq.top());
                lq.pop();
            }

            while (mp.count(lq.top()) && (mp[lq.top()] > 0)) {
                --mp[lq.top()];
                lq.pop();
            }

            while (mp.count(rq.top()) && (mp[rq.top()] > 0)) {
                --mp[rq.top()];
                rq.pop();
            }
        }
        res.push_back((k % 2 == 0) ? ((double)lq.top() + (double)rq.top()) * 0.5 :
            lq.top());

        return res;
    }
};
// @lc code=end

