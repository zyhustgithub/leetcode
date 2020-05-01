/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    bool IsNumber(char ch)
    {
        if ((ch >= '0') && (ch <= '9')) {
            return true;
        }
        return false;
    }

    bool IsSigned(char ch)
    {
        if ((ch == '-') || (ch == '+')) {
            return true;
        }
        return false;
    }

    int Str2Num(string &str, bool signFlag)
    {
        constexpr int MAX_EXP = 9;
        constexpr int MAX_NUM = 2;
        constexpr int BASE = 10;
        int strLen = str.size();
        int tmp = 0;
        int exp = 0;
        for (auto s : str) {
            s = s - '0';
            if ((exp > MAX_EXP) || ((exp == MAX_EXP) && (s > MAX_NUM))) {
                return (signFlag ? INT_MAX : INT_MIN);
            }
            if (exp == MAX_EXP) {
                if (signFlag) {
                    if ((exp == MAX_EXP) && (s == MAX_NUM) &&
                        (tmp >= INT_MAX % (int)pow(BASE, MAX_EXP))) {
                        return INT_MAX;
                    }
                } else {
                    if ((exp == MAX_EXP) && (s == MAX_NUM) &&
                        (tmp >= INT_MAX % (int)pow(BASE, MAX_EXP) + 1)) {
                        return INT_MIN;
                    }
                }
            }
            tmp += s * pow(BASE, exp);
            ++exp;
        }
        return (signFlag ? tmp : -tmp);
    }

    int myAtoi(string str)
    {
        bool signFlag = true;
        int pos = 0;
        int strLen = str.length();
        for (auto x : str) {
            if (x != ' ') {
                break;
            }
            ++pos;
        }

        if (IsSigned(str[pos])) {
            if (str[pos] == '-') {
                signFlag = false;
            }
            ++pos;
        } else {
            if (!IsNumber(str[pos])) {
                return 0;
            }
        }

        string tmp = "";
        while (str[pos] == '0') {
            ++pos;
        }
        while ((pos < strLen) && (IsNumber(str[pos]))) {
            tmp += str[pos];
            ++pos;
        }
        reverse(tmp.begin(), tmp.end());
        return Str2Num(tmp, signFlag);
    }
};
// @lc code=end

