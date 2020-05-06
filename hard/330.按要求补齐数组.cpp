/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
// class Solution {
// public:
//     int minPatches(vector<int>& nums, int n) {
//         long minNum = 1;
//         int res = 0;
//         for (auto val : nums) {
//             if (val > n) {
//                 break;
//             }
//             if (val <= minNum) {
//                 minNum += val;
//             } else {
//                 while (minNum < val) {
//                     ++res;
//                     minNum += minNum;
//                 }
//                 minNum = minNum + val;
//             }
//         }

//         while (minNum <= n) {
//             ++res;
//             minNum += minNum;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long minNum = 1;
        int res = 0;
        int pos = 0;
        while (minNum <= n) {
            if (pos < nums.size() && nums[pos] <= minNum) {
                minNum += nums[pos];
                ++pos;
            } else {
                ++res;
                minNum += minNum;
            }
        }
        return res;
    }
};
// @lc code=end

