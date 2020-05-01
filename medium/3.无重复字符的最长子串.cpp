/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pre = 0;
        int post = 0;
        int max = 0;
        int pos = 0;
        vector<char> vecCh;
        for (auto tmpChar : s) {
            ++pos;
            if (vecCh.empty()) {
                vecCh.push_back(tmpChar);
                if (max == 0) {
                    max = 1;
                }
            } else {
                auto it = find(vecCh.begin(), vecCh.end(), tmpChar);
                if (it != vecCh.end()) {
                    vecCh.erase(vecCh.begin(), it + 1);
                }
                vecCh.push_back(tmpChar);
                if (max < vecCh.size()) {
                    max = vecCh.size();
                }
            }
        }
        return max;
    }
};
// @lc code=end

