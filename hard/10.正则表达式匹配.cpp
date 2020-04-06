/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<bool>> match(sSize + 1, vector<bool>(pSize + 1, false));
        match[0][0] = true;
        for (int i = 0; i <= sSize; ++i) {
            for (int j = 1; j <= pSize; ++j) {
                if ((j > 1) && (p[j - 1] == '*')) {
                    if (i > 0) {
                        match[i][j] = match[i - 1][j] &&
                            ((p[j - 2] == s[i - 1]) || (p[j - 2] == '.'));
                    }
                    match[i][j] = (match[i][j] || match[i][j - 2]);
                } else if (i > 0) {
                    match[i][j] = (match[i - 1][j - 1]) && ((p[j - 1] == s[i - 1]) ||
                        (p[j - 1] == '.'));
                }
            }
        }
        return match[sSize][pSize];
    }
};
// @lc code=end

