/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string str) {
        if (str.empty()) {
            return "";
        }
        int cnt = 0;
        int start = 0;
        multiset<string, greater<string>> res;
        for (int idx = start; idx < str.size(); ++idx) {
            if (str[idx] == '1') {
                ++cnt;
            } else {
                --cnt;
            }

            if (cnt == 0) {
                res.insert('1' + makeLargestSpecial(str.substr(start + 1, idx - start - 1)) + '0');
                start = idx + 1;
            }
        }

        string ans;
        for (auto &s : res) {
            ans += s;
        }

        return ans;
    }
};
// @lc code=end

