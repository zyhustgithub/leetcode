/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int div = 1;
        int ans = 0;
        while (N > 0) { // 不能从0开始，所以要>0
            ans += (N % div == 0);
            N -= div;
            ++div;
        }

        return ans;
    }
};
// @lc code=end

