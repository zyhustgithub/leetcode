/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if (p.empty()) {
//             return s.empty();
//         }
        
//         int sSize = s.size();
//         int pSize = p.size();

//         vector<vector<bool>> match(sSize + 1, vector<bool>(pSize + 1, false));
//         match[0][0] = true;
//         for (int i = 0; i <= sSize; ++i) {
//             for (int j = 1; j <= pSize; ++j) {
//                 if (p[j - 1] == '*') {
//                     match[i][j] = match[i][j - 1];
//                     if (i > 0) {
//                         match[i][j] = match[i][j] || match[i - 1][j];
//                     }
//                 } else if (i > 0) {
//                     match[i][j] = match[i - 1][j - 1] && ((p[j - 1] == '?') ||
//                         (p[j - 1] == s[i - 1]));
//                 }
//             }
//         }
//         return match[sSize][pSize];
//     }
// };
class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        int sStar = -1;
        int pStar = -1;
        int i = 0;
        int j = 0;

        while (i < sSize) {
            if ((j < pSize) && (s[i] == p[j]) || (p[j] == '?')) {
                ++i;
                ++j;
            } else if ((j < pSize) && (p[j] == '*')) {
                sStar = i;
                pStar = j++;
            } else if (sStar >= 0) {
                i = ++sStar;
                j = pStar + 1;
            } else {
                return false;
            }
        }
        while ((p[j] == '*') && (j < pSize)) {
            ++j;
        }
        if (j == pSize) {
            return true;
        }
        return false;
    }
};
// @lc code=end

