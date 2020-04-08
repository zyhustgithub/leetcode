/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int strSize = s.size();
        vector<int> validPare(strSize, 0);
        int max = 0;
        for (int i = 1; i < strSize; ++i) {
            if (s[i] == '(') {
                validPare[i] = 0;
            } else {
                if ((i - validPare[i - 1] - 1 >= 0) &&
                    (s[i - validPare[i - 1] - 1] == '(')) {
                    validPare[i] = validPare[i - 1] + 2 +
                        ((i - validPare[i - 1] - 2 >= 0) ?
                        validPare[i - validPare[i - 1] - 2] :
                        0);
                } else {
                    validPare[i] = 0;
                }
                if (max < validPare[i]) {
                    max = validPare[i];
                }
            }
        }
        return max;
    }
};
// @lc code=end

