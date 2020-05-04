/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int strSize = s.size();
        for (int pos = 0; pos < strSize; ++pos) {
            mp[s[pos]] = pos;
        }

        stack<char> st;
        for (int pos = 0; pos < strSize; ++pos) {
            if (visit.count(s[pos]) != 0) {
                continue;
            }
            while (!st.empty() && (s[pos] < st.top()) &&
                (mp[st.top()] >= pos)) {
                visit.erase(st.top());
                st.pop();
            }

            if (visit.count(s[pos]) == 0) {
                st.push(s[pos]);
                visit.insert(s[pos]);
            }
        }
        string res("");
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    unordered_map<char, int> mp;
    unordered_set<char> visit;
};
// @lc code=end

