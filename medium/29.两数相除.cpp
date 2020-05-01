/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0) {
            return 0;
        }

        bool signFlag;
        if (((dividend > 0) && (divisor > 0)) ||
            ((dividend < 0) && (divisor < 0))) {
            signFlag = true; // 正数
        } else {
            signFlag = false; // 负数
        }
        dividend = (dividend > 0) ? -dividend : dividend;
        divisor = (divisor > 0) ? -divisor : divisor;

        if (divisor < dividend) {
            return 0;
        }
        
        if (divisor == -1) {
            if (signFlag && (dividend == INT_MIN)) {
                return INT_MAX;
            }
            return signFlag ? -dividend : dividend;
        }

        int res = Div(dividend, divisor);
        return signFlag ? res : -res;
    }

    int Div(int dividend, int divisor)
    {
        if (dividend > divisor) {
            return 0;
        }
        int divNum = 1;
        int tmpDiv = divisor;
        while (dividend - tmpDiv <= tmpDiv) {
            tmpDiv += tmpDiv;
            divNum += divNum;
        }
        return divNum + Div(dividend - tmpDiv, divisor);
    }
};
// @lc code=end

