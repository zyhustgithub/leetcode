/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!Cmp(m, n, k, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    bool Cmp(int m, int n, int k, int num)
    {
        int count = 0;
        for (int row = 1; row <= m; ++row) {
            count += min(n, num / row);
        }

        return (count >= k);
    }
};
// @lc code=end

