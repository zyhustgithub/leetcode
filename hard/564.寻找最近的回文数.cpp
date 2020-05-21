/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 */

// @lc code=start
class Solution {
public:
    string nearestPalindromic(string n) {
        long strSize = n.size();
        long splitNum = (strSize - 1) / 2;
        long rightNum = strSize / 2;
        long num = stoul(n);

        long leftNum = stoul(n.substr(0, splitNum + 1));
        long leftNumMid = reverseNum(to_string(leftNum), rightNum);
        long leftNumLow = (leftNum == powl(10, splitNum)) ? leftNum * powl(10, rightNum) - 1 :
            reverseNum(to_string(leftNum - 1), rightNum);
        long leftNumHigh = (leftNum + 1 == powl(10, splitNum + 1)) ? (leftNum + 1) *
            powl(10, rightNum) + 1 : reverseNum(to_string(leftNum + 1), rightNum);
        
        long min = 0;
        long diffLow = abs(leftNumLow - num);
        long diffMid = abs(leftNumMid - num);
        long diffHigh = abs(leftNumHigh - num);
        string res;
    
        if (diffMid != 0) {
            min = diffMid;
            res = to_string(leftNumMid);
        }
        if ((min == 0) || (diffMid >= diffLow)) {
            min = diffLow;
            res = to_string(leftNumLow);
        }
        if (diffHigh < min) {
            res = to_string(leftNumHigh);
        }
        return res;
    }

    long reverseNum(string leftNum, uint64_t rightNum)
    {
        if (leftNum.size() == rightNum) {
            return stoul(leftNum + string(leftNum.rbegin(), leftNum.rend()));
        } else {
            return stoul(leftNum + string(leftNum.rbegin() + 1, leftNum.rend()));
        }
    }
};
// @lc code=end

