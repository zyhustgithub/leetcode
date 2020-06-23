/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后K个零
 */

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int K) {
        // f(x) = (int)x/5 + (int)x/5^2 + (int)x/5^3 + ... <= x/5 + x/5^2 + x/5^3 + ... < x/4
        // x > 4 * K; x < 5 * K + 1,增加了一个5，＋1是因为左偏二分
        unsigned long left = 4 * (unsigned long)K;
        unsigned long right = 5 * (unsigned long)K + 1;

        while (left < right) {
            unsigned long mid = (left + right) / 2;
            int num = FiveNums(mid);
            if (num == K) {
                return 5;
            } else if (num < K) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return 0;
    }

    int FiveNums(unsigned long num)
    {
        if (num < 5) {
            return 0;
        }
        return num / 5 + FiveNums(num / 5);
    }
};
// @lc code=end

