/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<bool> stat(s2.size() + 1, false);
        stat[0] = true;
        int pos1 = 0;
        int pos2 = 0;
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if ((i > 0) && (s1[i - 1] != s3[i + j - 1])) {
                    stat[j] = false;
                }

                if ((j > 0) && (s2[j - 1] == s3[i + j - 1])) {
                    stat[j] = stat[j] || stat[j - 1];
                }
            }
        }
        return stat[s2.size()];
    }
};
// @lc code=end

