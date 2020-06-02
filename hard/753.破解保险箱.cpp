/*
 * @lc app=leetcode.cn id=753 lang=cpp
 *
 * [753] 破解保险箱
 */

// @lc code=start
class Solution {
public:
    string crackSafe(int n, int k) {
        int count = pow(k, n);
        string res(n, '0');
        unordered_set<string> seen;
        seen.insert(res);

        for (int i = 0; i < count; ++i) {
            string cur = res.substr(res.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; --j) {
                cur += ('0' + j);
                if (seen.count(cur) == 0) {
                    seen.insert(cur);
                    res += ('0' + j);
                    break;
                }
                cur.pop_back();
            }
        }

        return res;
    }
};
// @lc code=end

