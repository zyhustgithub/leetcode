/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * [664] 奇怪的打印机
 */

// @lc code=start
class Solution {
public:
    int strangePrinter(string s) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), 0));
        return DFS(s, 0, s.size() - 1);
    }

    int DFS(string &s, int pre, int post)
    {
        if (pre > post) {
            return 0;
        }

        if (dp[pre][post] != 0) {
            return dp[pre][post];
        }

        int ans = 1 + DFS(s, pre + 1, post);
        for (int idx = pre + 1; idx <= post; ++idx) {
            if(s[idx] == s[pre]) {
                ans = min(ans, DFS(s, pre, idx - 1) + DFS(s, idx + 1, post));
            }
        }

        dp[pre][post] = ans;
        return ans;
    }

private:
    vector<vector<int>> dp;
};
// @lc code=end

