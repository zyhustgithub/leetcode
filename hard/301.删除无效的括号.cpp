/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftNum = 0;
        int rightNum = 0;
        int sSize = s.size();
        for (int pos = 0; pos < sSize; ++pos) {
            if (s[pos] == '(') {
                ++leftNum;
            } else if (s[pos] == ')') {
                (leftNum > 0) ? --leftNum : ++rightNum;
            }
        }

        set<string> res;
        stack<char> st;
        string path("");
        DFS(s, leftNum, rightNum, 0, path, st, res);
        return vector<string>(res.begin(), res.end());
    }

    void DFS(string &s, int leftNum, int rightNum, int index, string &path,
        stack<char> &st, set<string> &res)
    {
        if (index == s.size()) {
            if ((leftNum == 0) && (rightNum == 0) && st.empty()) {
                res.insert(path);
            }
            return;
        }

        int pathSize = path.size();
        if (s[index] == '(') {
            path += "(";
            st.push('(');
            DFS(s, leftNum, rightNum, index + 1, path, st, res);
            path.resize(pathSize);
            st.pop();
            if (leftNum > 0) {
                DFS(s, leftNum - 1, rightNum, index + 1, path, st, res);
            }
        } else if (s[index] == ')') {
            if (!st.empty()) {
                path += ")";
                st.pop();
                DFS(s, leftNum, rightNum, index + 1, path, st, res);
                path.resize(pathSize);
                st.push('(');
            }

            if (rightNum > 0) {
                DFS(s, leftNum, rightNum - 1, index + 1, path, st, res);
            }
        } else {
            path += s[index];
            DFS(s, leftNum, rightNum, index + 1, path, st, res);
            path.resize(pathSize);
        }
    }
};
// @lc code=end

