/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int num1Size = num1.size();
        int num2Size = num2.size();
        string res(num1Size + num2Size, '0');
        for (int i = num1Size - 1; i >= 0; --i) {
            for (int j = num2Size - 1; j >= 0; --j) {
                int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = tmp % 10 + '0';
                res[i + j] += tmp / 10;
            }
        }
        
        for (int pos = 0; pos < res.size(); ++pos) {
            if (res[pos] != '0') {
                return res.substr(pos, res.size());
            }
        }
        return "0";
        
    }
};
// @lc code=end

