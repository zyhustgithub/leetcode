/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        map<int, vector<int>> mp;

        for (int idx = 0; idx < s.size(); ++idx) {
            mp[s[idx]].push_back(idx);
        }

        int ans = 0;

        for (auto &it : mp) {
            it.second.insert(it.second.begin(), -1);
            it.second.push_back(s.size());
            for (int pos = 1; pos < it.second.size() - 1; ++pos) {
                ans += (it.second[pos] - it.second[pos - 1]) *
                    (it.second[pos + 1] - it.second[pos]);
            }
        }

        return ans;
    }
};
// @lc code=end

