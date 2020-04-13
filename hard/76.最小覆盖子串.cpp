/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        if (sSize < tSize) {
            return "";
        }
        int l, r;
        map<char, int> rec;
        for (auto n : t) {
            ++rec[n];
        }

        int num = 0;
        int len = 0;
        int beg = 0;
        for (l = 0, r = 0; r < sSize; ++r) {
            --rec[s[r]];
            if (rec[s[r]] >= 0) {
                ++num;
            }

            while (num == tSize) {
                while (++rec[s[l]] <= 0) {
                    ++l;
                }
                if ((r - l + 1 < len) || (len == 0)) {
                    len = r - l + 1;
                    beg = l;
                }
                --num;
                ++l;
            }
        }
        return s.substr(beg, len);
    }
};
// @lc code=end

