/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

#if 0
class Solution {
public:
    int minSwap(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int nIdx = 0;
        int steps = 0;
        DFS(nums1, nums2, nIdx, steps);

        return m_minSteps;
    }

    void DFS(std::vector<int>& lhs, std::vector<int>& rhs, int& nIdx, int& steps)
    {
        int arrSize = static_cast<int>(lhs.size());
        if (nIdx == arrSize) {
            m_minSteps = std::min(m_minSteps, steps);
            return;
        }

        if (nIdx > 0) {
            if (lhs[nIdx - 1] >= std::max(lhs[nIdx], rhs[nIdx])) {
                return;
            }

            if (rhs[nIdx - 1] >= std::max(lhs[nIdx], rhs[nIdx])) {
                return;
            }

            if (lhs[nIdx - 1] >= lhs[nIdx] && rhs[nIdx - 1] >= lhs[nIdx]) {
                return;
            }

            if (rhs[nIdx - 1] >= rhs[nIdx] && lhs[nIdx - 1] >= rhs[nIdx]) {
                return;
            }

            int pos = nIdx++;
            if ((lhs[pos - 1] < lhs[pos]) && (rhs[pos - 1] < rhs[pos])) {
                DFS(lhs, rhs, nIdx, steps);
            }

            if ((lhs[pos - 1] < rhs[pos]) && (rhs[pos - 1] < lhs[pos])) {
                lhs[pos] ^= rhs[pos];
                rhs[pos] ^= lhs[pos];
                lhs[pos] ^= rhs[pos];
                DFS(lhs, rhs, nIdx, ++steps);
                --steps;
                lhs[pos] ^= rhs[pos];
                rhs[pos] ^= lhs[pos];
                lhs[pos] ^= rhs[pos];
            }

            --nIdx;
        } else {
            int pos = nIdx++;
            DFS(lhs, rhs, nIdx, steps);

            lhs[pos] ^= rhs[pos];
            rhs[pos] ^= lhs[pos];
            lhs[pos] ^= rhs[pos];

            DFS(lhs, rhs, nIdx, ++steps);

            --nIdx;
            --steps;
            lhs[pos] ^= rhs[pos];
            rhs[pos] ^= lhs[pos];
            lhs[pos] ^= rhs[pos];
        }
    }

private:
    int m_minSteps = 0x3f3f3f3f;
};
#endif

class Solution {
public:
    int minSwap(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int nNoSwap = 0;
        int nSwap = 1;
        for (int idx = 1; idx < nums1.size(); ++idx) {
            int nTmpNoSwap = INT_MAX;
            int nTmpSwap = INT_MAX;
            if ((nums1[idx - 1] < nums1[idx]) && (nums2[idx - 1] < nums2[idx])) {
                nTmpNoSwap = std::min(nTmpNoSwap, nNoSwap);
                nTmpSwap = std::min(nTmpSwap, nSwap + 1);
            }

            if ((nums1[idx - 1] < nums2[idx]) && (nums2[idx - 1] < nums1[idx])) {
                nTmpNoSwap = std::min(nTmpNoSwap, nSwap);
                nTmpSwap = std::min(nTmpSwap, nNoSwap + 1);
            }

            nNoSwap = nTmpNoSwap;
            nSwap = nTmpSwap;
        }

        return std::min(nNoSwap, nSwap);
    }
};

// int main()
// {
//     std::vector<int> vecNumsLhs{ 0,7,8,10,10,11,12,13,19,18 };
//     std::vector<int> vecNumsRhs{ 4,4,5,7,11,14,15,16,17,20 };

//     Solution sl{};
//     int res = sl.minSwap(vecNumsLhs, vecNumsRhs);
//     std::cout << res << std::endl;
//     return 0;
// }
// @lc code=end