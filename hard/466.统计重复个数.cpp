/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

// @lc code=start
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        
        int pos = 0;
        for (int idx = 0; idx < n1; ++idx) {
            for (auto ch: s1) {
                if (s2[pos] == ch) {
                    ++pos;
                    if (pos == s2.size()) {
                        ++cnt2;
                        pos = 0;
                    }
                }
            }
            ++cnt1;
            if (cnt1 == n1) {
                return cnt2 / n2;
            }
            if (mp.count(pos) == 0) {
                mp[pos] = {cnt1, cnt2};
            } else {
                break;
            }
        }

        int num = mp[pos].second +
            ((n1 - mp[pos].first) / (cnt1 - mp[pos].first)) * (cnt2 - mp[pos].second);
        int left = (n1 - mp[pos].first) % (cnt1 - mp[pos].first);

        while (left--) {
            for (auto ch: s1) {
                if (ch == s2[pos]) {
                    ++pos;
                    if (pos == s2.size()) {
                        ++num;
                        pos = 0;
                    }
                }
            }
        }

        return num / n2;
    }

private:
    unordered_map<int, pair<int, int>> mp;
};
// @lc code=end

