/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // bool

bool isMatch(char *s, char *p){
    size_t sLen = strlen(s);
    size_t pLen = strlen(p);
    bool dp[sLen + 1][pLen + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (size_t i = 0; i <= sLen; ++i) {
        for (size_t j = 1; j <= pLen; ++j) {
            if (p[j - 1] == '*') {
                if (j == 1) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j] && ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.'));
                }
                dp[i][j] = dp[i][j] || dp[i][j - 2];
            } else {
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j - 1] && ((s[i - 1] == p[j - 1]) || (p[j - 1] == '.'));
                }
            }
        }
    }

    return dp[sLen][pLen];
}


// @lc code=end

