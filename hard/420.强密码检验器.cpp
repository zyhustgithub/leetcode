/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */

// @lc code=start
struct Cmp {
    bool operator()(int a, int b)
    {
        return ((a % 3) > (b % 3));
    }
};

class Solution {
public:
    int strongPasswordChecker(string s) {
        priority_queue<int, vector<int>, Cmp> pq;

        int strSize = s.size();
        bool hasLow = false;
        bool hasHigh = false;
        bool hasDigit = false;
        int pre = 0;
        for (int pos = 0; pos < strSize; ++pos) {
            if ((pos != 0) && (s[pos] != s[pos - 1])) {
                if (pos - pre >= 3) {
                    pq.push(pos - pre);
                }
                pre = pos;
            }
            if ((s[pos] >= 'a') && (s[pos] <= 'z')) {
                hasLow = true;
            } else if ((s[pos] >= 'A') && (s[pos] <= 'Z')) {
                hasHigh = true;
            } else {
                hasDigit = true;
            }
        }
        if (strSize - pre >= 3) {
            pq.push(strSize - pre);
        }

        int res = 0;
        if (strSize < 6) {
            int num = 6 - strSize;
            res += num;

            while (num--) {
                if (!hasLow) {
                    hasLow = true;
                } else if (!hasHigh) {
                    hasHigh = true;
                } else if (!hasDigit) {
                    hasDigit = true;
                } else {
                    break;
                }
            }
            
        } else {
            if (strSize > 20) {
                int num = strSize - 20;
                res += num;
                while (num-- && !pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    // cout << top << endl;
                    if (--top >= 3) {
                        pq.push(top);
                    }
                }
            }

            while (!pq.empty()) {
                int num = pq.top() / 3;
                pq.pop();
                res += num;
                while (num--) {
                    if (!hasLow) {
                        hasLow = true;
                    } else if (!hasHigh) {
                        hasHigh = true;
                    } else if (!hasDigit) {
                        hasDigit = true;
                    } else {
                        break;
                    }
                }
            }
        }

        if (!hasLow) {
            ++res;
        }
        if (!hasHigh) {
            ++res;
        }
        if (!hasDigit) {
            ++res;
        }

        return res;
    }
};
// @lc code=end

