/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int aSize = A.size();
        if (aSize == 1) {
            return false;
        }
        int avg = 0;
        for (auto &num : A) {
            avg += num;
            num *= aSize;
        }

        for (auto &num : A) {
            num -= avg;
        }

        vector<int> left;
        vector<int> right;

        int leftSum = 0;
        for (int idx = 0; idx <= (aSize - 1) / 2; ++idx) {
            int leftSize = left.size();
            for (int pos = 0; pos < leftSize; ++pos) {
                left.push_back(left[pos] + A[idx]);
            }
            left.push_back(A[idx]);
            leftSum += A[idx];
        }

        int rightSum = 0;
        for (int idx = (aSize - 1) / 2 + 1; idx < aSize; ++idx) {
            int rightSize = right.size();
            for (int pos = 0; pos < rightSize; ++pos) {
                right.push_back(right[pos] + A[idx]);
            }
            right.push_back(A[idx]);
            rightSum += A[idx];
        }

        set<int> leftSet(left.begin(), left.end());
        if (leftSet.count(0) > 0) {
            return true;
        }
        leftSet.erase(leftSum);
        unordered_set<int> rightSet(right.begin(), right.end());
        if (rightSet.count(0) > 0) {
            return true;
        }

        for (auto num : leftSet) {
            if (rightSet.count(-num) > 0) {
                return true;
            }
        }
        
        return false;
    }
};
// @lc code=end

