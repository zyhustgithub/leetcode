/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        long num = 0;
        long res = 0;
        long sign = 1;
        stack<long> st;

        for (auto ch : s) {
            if ((ch >= '0') && (ch <= '9')) {
                num = (num * 10 + (ch - '0'));
            } else if (ch == '+') {
                res += num * sign;
                sign = 1;
                num = 0;
            } else if (ch == '-') {
                res += num * sign;
                sign = -1;
                num = 0;
            } else if (ch == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
                num = 0;
            } else if (ch == ')') {
                res += sign * num;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
                num = 0;
                sign = 1;
            }
        }
        return res + num * sign;
    }
};
// @lc code=end

