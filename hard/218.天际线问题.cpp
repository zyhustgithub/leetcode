/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> ms;
        vector<vector<int>> res;
        for (auto &v : buildings) {
            ms.insert(make_pair(v[0], -v[2]));
            ms.insert(make_pair(v[1], v[2]));
        }

        multiset<int> st{0};
        int maxheight = 0;
        for (auto &m : ms) {
            if (m.second < 0) {
                st.insert(-m.second);
            } else {
                st.erase(st.find(m.second));
            }
    
            if (*st.rbegin() != maxheight) {
                maxheight = *st.rbegin();
                res.push_back({m.first, maxheight});
            }
        }
        return res;
    }
};
// @lc code=end

