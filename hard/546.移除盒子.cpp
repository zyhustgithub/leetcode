/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 */

// @lc code=start
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int boxSize = boxes.size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(boxSize, vector<vector<int>>
            (boxSize, vector<int>(boxSize, 0)));
        return DFS(dp, boxes, 0, boxSize - 1, 0);
    }

    int DFS(vector<vector<vector<int>>> &dp, vector<int>& boxes, int left, int right, int sames)
    {
        if (left > right) {
            return 0;
        }

        while ((right > left) && (boxes[right - 1] == boxes[right])) {
            --right;
            ++sames;
        }

        if (dp[left][right][sames] != 0) {
            return dp[left][right][sames];
        }

        int ans = DFS(dp, boxes, left, right - 1, 0) + (sames + 1) * (sames + 1);
        int idx = left;
        while (idx < right) {
            if (boxes[idx] == boxes[right]) {
                ans = max(ans, DFS(dp, boxes, left, idx, sames + 1) +
                    DFS(dp, boxes, idx + 1, right - 1, 0));
            }
            ++idx;
        }
        dp[left][right][sames] = ans;

        return ans;
    }
};
// @lc code=end

