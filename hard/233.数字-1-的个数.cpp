/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        int pos = 1;
        int res = 0;
        do {
            int left = (n / pos) / 10;
            int mid = (n / pos) % 10;
            int right = n % pos;
            res += left * pos;

            if (mid > 1) {
                res += pos;
            }

            if (mid == 1) {
                res += (right + 1);
            }
            if (left == 0) {
                break;
            }
            pos *= 10;
        } while (n / pos > 0);

        return res;
    }
};
// @lc code=end

