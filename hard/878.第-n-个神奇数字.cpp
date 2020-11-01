/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start

#include <iostream>
#include <tuple>

constexpr int MOD_NUM = 1000000007;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int lcm = (A * B) / Gcd(A, B);
        int perLcmNum = (lcm / A) + (lcm / B) - 1;
        int left = N % perLcmNum;
        long curNum = (static_cast<long>(N / perLcmNum) * lcm) % MOD_NUM;

        if (left == 0) {
            return static_cast<int>(curNum);
        }

        std::pair<int, int> head(std::make_pair(A, B));
        for (int idx = 1; idx < left; ++idx) {
            if (head.first < head.second) {
                head.first += A;
            } else {
                head.second += B;
            }
        }

        return static_cast<int>((curNum + std::min(head.first, head.second)) % MOD_NUM);
    }

    int Gcd(int a, int b)
    {
        if (b == 0) {
            return a;
        } else {
            return Gcd(b, a % b);
        }
    }
};
// @lc code=end

