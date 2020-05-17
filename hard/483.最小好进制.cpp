/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */

// @lc code=start
class Solution {
public:
    string smallestGoodBase(string n) {
        uint64_t num = atoll(n.c_str());
        uint64_t maxExp = log2(num);

        for (uint64_t exp = maxExp; exp > 0; --exp) {
            uint64_t right = powl(num, 1.0 / exp);
            uint64_t left = 2;
            uint64_t mid = left + (right - left) / 2;
            while (left <= right) {
                uint64_t sum = 1;
                for (int idx = 0; idx < exp; ++idx) {
                    sum = sum * mid + 1;
                }
                if (sum == num) {
                    return to_string(mid);
                } else if (sum < num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                mid = left + (right - left) / 2;
            }
        }

        return "";
    }
};
// @lc code=end

