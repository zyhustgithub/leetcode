/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int machinesNum = machines.size();
        if (machinesNum == 0) {
            return -1;
        }
        vector<int> sum(machinesNum, 0);
        sum[0] = machines[0];
        for (int idx = 1; idx < machinesNum; ++idx) {
            sum[idx] = sum[idx - 1] + machines[idx];
        }
        if (sum.back() % machinesNum != 0) {
            return -1;
        }
        int avg = sum.back() / machinesNum;
        
        int leftNum = 0;
        int rightNum = 0;

        int res = 0;
        for (int idx = 1; idx < machinesNum; ++idx) {
            leftNum = sum[idx - 1] - avg * idx;
            rightNum = sum.back() - sum[idx] - avg * (machinesNum - idx - 1);
            if ((leftNum < 0) && (rightNum < 0)) {
                res = max(res, abs(leftNum) + abs(rightNum));
            } else {
                res = max(res, max(abs(leftNum), abs(rightNum)));
            }
        }

        return res;
    }
};
// @lc code=end

