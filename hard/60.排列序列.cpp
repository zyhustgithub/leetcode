/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start

#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k)
    {
        m_maxNum = n;
        m_nIdx = k;
        std::string strNum{};
        int32_t nIdx = 0;
        DFS(strNum, nIdx);

        return strNum;
    }

    int32_t Factorial(int32_t num)
    {
        if (num < 1) {
            return 0;
        }

        int res = 1;
        for (int idx = 1; idx <= num; ++idx) {
            res *= idx;
        }

        return res;
    }

    void DFS(std::string& strNum, int32_t& nIdx)
    {
        if (strNum.size() == m_maxNum) {
            ++nIdx;
            --m_nIdx;
            return;
        }

        int32_t nConditions = Factorial(m_maxNum - strNum.size());
        if (nConditions < m_nIdx) {
            nIdx += nConditions;
            m_nIdx -= nConditions;
            return;
        }

        for (int32_t idx = 1; idx <= m_maxNum; ++idx) {
            if (m_visited & (1 << (idx - 1))) {
                continue;
            }
            m_visited |= (1 << (idx - 1));

            strNum.append(std::to_string(idx));
            DFS(strNum, nIdx);

            if (m_nIdx == 0) {
                return;
            }

            m_visited ^= (1 << (idx - 1));
            strNum.pop_back();
        }
    }

private:
    int32_t m_maxNum = 0;
    int32_t m_nIdx = 0;
    uint32_t m_visited = 0;
};
// @lc code=end

