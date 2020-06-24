/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int aSize = A.size();
        vector<int> count(aSize, 0);

        for (int idx = 0; idx < aSize; ++idx) {
            int left = (idx - A[idx] + 1 + aSize) % aSize;
            int right = (idx + 1) % aSize;

            ++count[right];
            --count[left];
            if (left > right) {
                --count[0];
            }
        }
        
        int ans = 0;
        int cnt = 0;
        int maxCnt = -0x3f3f3f;
        for (int idx = 0; idx < aSize; ++idx) {
            cnt += count[idx];
            if (maxCnt < cnt) {
                maxCnt = cnt;
                ans = idx;
            }
        }

        return ans;
    }
};
// @lc code=end

