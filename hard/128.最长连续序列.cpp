/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) {
//             return 0;
//         }
//         for (int n : nums) {
//             st[n] = n;
//             cnt[n] = 1;
//         }

//         int ans = 1;
//         for (int n : nums) {
//             if (st.count(n + 1) > 0) {
//                 ans = max(ans, Merge(n, n + 1));
//             }
//         }
//         return ans;
//     }

//     int FindParent(int x)
//     {
//         if (st[x] == x) {
//             return x;
//         }
//         st[x] = st[FindParent(st[x])];
//         return st[x];
//     }

//     int Merge(int x, int y)
//     {
//         x = FindParent(x);
//         y = FindParent(y);
//         if (x == y) {
//             return cnt[x];
//         }
//         st[y] = st[x];
//         cnt[x] += cnt[y];
//         return cnt[x];
//     }

// private:
//     unordered_map<int, int> st;
//     unordered_map<int, int> cnt;
// };

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> st(nums.begin(), nums.end());
//         int res = 0;
//         for (int n : st) {
//             if (st.count(n - 1) == 0) {
//                 int cnt = 1;
//                 while (st.count(n + 1)) {
//                     ++cnt;
//                     ++n;
//                 }
//             res = (res < cnt) ? cnt : res;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int x: nums) {
            if (!dp[x]) {
                dp[x] = dp[x - 1] + dp[x + 1] + 1;
                dp[x - dp[x - 1]] = dp[x];
                dp[x + dp[x + 1]] = dp[x];
            }
            res = max(res, dp[x]);
        }
        return res;
    }
};
// @lc code=end

