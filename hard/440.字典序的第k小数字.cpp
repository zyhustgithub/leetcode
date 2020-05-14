/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        uint64_t cur = 1;
        --k;
        while (k) {
            uint64_t left = cur;
            uint64_t right = cur + 1;
            uint64_t steps = 0;

            while (left <= n) {
                steps += (min((uint64_t)n + 1, right) - left);
                left *= 10;
                right *= 10;
            }

            if (k >= steps) {
                k -= steps;
                ++cur;
            } else {
                --k;
                cur *= 10;
            }
        }

        return cur;
    }
};
// @lc code=end

