/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        string newStr = s + "#" + revStr;
        int newStrSize = newStr.size();

        vector<int> next(newStrSize, 0);
        int pre = 0;
        for (int pos = 1; pos < newStrSize; ++pos) {
            pre = next[pos - 1];
            while ((pre > 0) && (newStr[pre] != newStr[pos])) {
                pre = next[pre - 1];
            }

            if(newStr[pos] == newStr[pre]) {
                ++pre;
            }
            next[pos] = pre;
        }

        return revStr.substr(0, s.size() - next[newStrSize - 1]) + s;
    }
};
// @lc code=end

