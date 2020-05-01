/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        m_digits = digits;
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        RecurseStr(res, "", 0);
        return res;
    }

    void RecurseStr(vector<string> &res, string s, int num)
    {
        if (num == m_digits.size()) {
            if (!s.empty()) {
                res.push_back(s);
                return;
            }
        } else {
            string tmp = m_vecStr[m_digits[num] - '0' - 2];
            for (auto n : tmp) {
                s += n;
                RecurseStr(res, s, num + 1);
                s.pop_back();
            }
        }
    }
private:
    string m_digits;
    vector<string> m_vecStr = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
                               "tuv", "wxyz"};
};
// @lc code=end

