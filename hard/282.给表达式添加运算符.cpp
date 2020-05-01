/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string opStr("");
        DFS(num, target, 0, 0, 0, res, opStr);
        return res;
    }

    void DFS(string &num, int target, int idx, int pre, long val, vector<string> &res,
        string &opStr)
    {
        int numSize = num.size();
        if (idx == numSize) {
            if (val == target) {
                res.push_back(opStr);
            }
            return;
        }

        int strSize = opStr.size();
        for (int pos = idx; pos < numSize; ++pos) {
            string tmpStrNum = num.substr(idx, pos - idx + 1);
            long tmpNum = stol(tmpStrNum);
            if (idx == 0) {
                opStr += tmpStrNum;
                DFS(num, target, pos + 1, tmpNum, val + tmpNum, res, opStr);
            } else {
                opStr += ("+" + tmpStrNum);
                DFS(num, target, pos + 1, tmpNum, val + tmpNum, res,
                    opStr);
                opStr.resize(strSize);

                opStr += ("-" + tmpStrNum);
                DFS(num, target, pos + 1, -tmpNum, val - tmpNum, res,
                    opStr);
                opStr.resize(strSize);

                opStr += ("*" + tmpStrNum);
                DFS(num, target, pos + 1, (long)pre * tmpNum, val - pre + (long)pre * tmpNum,
                    res, opStr);
            }
            opStr.resize(strSize);

            if (tmpNum == 0) {
                break;
            }
        }
    }
};
// @lc code=end

