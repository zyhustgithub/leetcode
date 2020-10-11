/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> sum{0};
        for (int num : A) {
            sum.push_back(sum.back() + num);
        }

        deque<int> dt;
        int ans = 0x3f3f3f;
        for (int idx = 0; idx < sum.size(); ++idx) {
            while (!dt.empty() && (sum[idx] <= sum[dt.back()])) {
                dt.pop_back();
            }

            while (!dt.empty() && (sum[idx] - sum[dt.front()] >= K)) {
                ans = min(ans, idx - dt.front());
                dt.pop_front();
            }

            dt.push_back(idx);
        }

        return (ans == 0x3f3f3f) ? -1 : ans;
    }
};
// @lc code=end

