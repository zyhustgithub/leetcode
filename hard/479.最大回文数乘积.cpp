/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */

// @lc code=start
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int maxNum = pow(10, n) - 1;
        int minNum = pow(10, n - 1);

        for (int num = maxNum - 1; num >= minNum; --num) {
            int tmp = num;
            unsigned long curNum = num;
            while (tmp > 0) {
                curNum = curNum * 10 + (unsigned long)tmp % 10;
                tmp = tmp / 10;
            }

            for (int div = maxNum; div >= sqrt(curNum); --div) {
                if (curNum % div == 0) {
                    return curNum % 1337;
                }
            }
        }

        return 0;
    }
};
// @lc code=end

