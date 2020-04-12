/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        int strSize = s.size();
        int state = 0;
        int pos = 0;
        int end = strSize - 1;
        while (pos < strSize) {
            if (s[pos] != ' ') {
                break;
            }
            ++pos;
        }
        while (end >= 0) {
            if (s[end] != ' ') {
                break;
            }
            --end;
        }
        for (; pos <= end; ++pos) {
            switch (s[pos]) {
                case '+':
                case '-':
                    if (state == 0) {
                        state = 1;
                    } else if (state == 5) {
                        state = 6;
                    } else {
                        return false;
                    }
                    break;
                case '.':
                    if ((state == 0) || (state == 1)) {
                        state = 2;
                    } else if (state == 3) {
                        state = 8;
                    } else {
                        return false;
                    }
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if ((state == 2) || (state == 4) || (state == 8)) {
                        state = 4;
                    } else if ((state == 0) || (state == 1) || (state == 3)) {
                        state = 3;
                    } else if ((state == 5) || (state == 6) || (state == 7)) {
                        state = 7;
                    } else {
                        return false;
                    }
                    break;
                case 'e':
                    if ((state == 3) || (state == 4) || (state == 8)) {
                        state = 5;
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        if ((state == 3) || (state == 4) || (state == 7) || (state == 8)) {
            return true;
        }
        return false;
    }
};
// @lc code=end

