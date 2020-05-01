/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(res, "", n, n);
        return res;
    }

    void DFS(vector<string> &res, string str, int lNum, int rNum)
    {
        if ((lNum == 0) && (rNum == 0)) {
            res.push_back(str);
            return;
        }

        if (lNum > 0) {
            DFS(res, str + "(", lNum - 1, rNum);
        }

        if ((rNum > 0) && (rNum != lNum)) {
            DFS(res, str + ")", lNum, rNum - 1);
        }
    }
};
// @lc code=end

