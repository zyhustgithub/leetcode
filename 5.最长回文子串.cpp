/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string tmpStr = "";
        for (auto c : s) {
            tmpStr += "#";
            tmpStr += c;
        }
        tmpStr += "#";
        int strLen = tmpStr.size();
        int rl[strLen];
        int prePos = 0;
        int postPos = 0;
        int maxPos = 0;
        int maxrl = 0;
        for (int pos = 0; pos < strLen - 1; ++pos) {
            if (strLen - pos < maxrl) {
                break;
            }
            if (pos < postPos) {
                rl[pos] = min(rl[2 * prePos - pos], postPos - pos + 1);
            } else {
                rl[pos] = 1;
            }
            while ((pos - rl[pos] >= 0) &&
                   (pos + rl[pos] < strLen) &&
                   (tmpStr[pos - rl[pos]] == tmpStr[pos + rl[pos]]) ) {
                ++rl[pos];
            }
            if (pos + rl[pos] - 1 > postPos) {
                postPos = pos + rl[pos] - 1;
                prePos = pos;
            }
            if (rl[pos] > maxrl) {
                maxPos = pos;
                maxrl = rl[pos];
            }
        }
        return s.substr((maxPos - maxrl + 1) / 2, maxrl - 1);
    }
};
// @lc code=end

