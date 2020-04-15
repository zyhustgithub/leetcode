/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    ~Solution()
    {
        delete [] mark;
        delete [] res;
    }
    bool isScramble(string s1, string s2) {
        if ((s1.size() != s2.size()) || s1.empty()) {
            return false;
        }

        int strSize = s1.size();
        mark = new bool[strSize * strSize * strSize];
        (void)memset(mark, 0, strSize * strSize * strSize * sizeof(bool));
        res = new bool[strSize * strSize * strSize];
        area = strSize * strSize;
        return IsMatch(s1, s2, 0, 0, strSize);
    }

    bool IsMatch(string &s1, string &s2, int l, int r, int len)
    {
        if (len == 1) {
            return (s1[l] == s2[r]);
        }
        int strSize = s1.size();
        int pos = l * area + r * strSize + len - 1;
        if (mark[pos]) {
            return res[pos];
        }

        bool result = false;
        for (int i = l + 1; i <= l + len - 1; ++i) {
            int nextLen = i - l;
            if (IsMatch(s1, s2, l, r, nextLen)) {
                if (IsMatch(s1, s2, i, r + nextLen, len - nextLen)) {
                    result = true;
                    break;
                }
            }

            if (IsMatch(s1, s2, l, r + len - nextLen, nextLen)) {
                if (IsMatch(s1, s2, i, r, len - nextLen)) {
                    result = true;
                    break;
                }
            }
        }

        mark[pos] = true;
        res[pos] = result;
        return result;
    }

public:
    int area;
    bool *mark;
    bool *res;
};
// @lc code=end

