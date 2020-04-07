/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        unordered_map<string, int> wordsMap;
        for (auto &x : words) {
            ++wordsMap[x];
        }
        int left = 0;
        int right = 0;
        int len = words[0].size();
        int wordsNum = words.size();
        vector<int> ans;
        int cnt = 0;
        unordered_map<string, int> matchMap;
        for (int i = 0; i < len; ++i) {
            left = i;
            right = left;
            cnt = 0;
            matchMap.clear();
            while (left + wordsNum * len <= s.size()) {
                string tmp;
                while (cnt < wordsNum) {
                    tmp = s.substr(right, len);
                    if (wordsMap.find(tmp) == wordsMap.end() ||
                        matchMap[tmp] >= wordsMap[tmp]) {
                        break;
                    }
                    ++cnt;
                    ++matchMap[tmp];
                    right += len;
                }
                if (matchMap == wordsMap) {
                    ans.push_back(left);
                }

                if (wordsMap.find(tmp) != wordsMap.end()) {
                    --matchMap[s.substr(left, len)];
                    left += len;
                    --cnt;
                } else {
                    cnt = 0;
                    right += len;
                    left = right;
                    matchMap.clear();
                }
            }
        }
        return ans;
    }
};
// @lc code=end

