/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         if (!IfWordBreak(s, wordDict)) {
//             return {};
//         }
//         uint32_t sSize = s.size();
//         vector<vector<string>> dp(sSize + 1, vector<string>{});
//         dp[0] = {""};

//         uint32_t endPos = 0;
//         for (uint32_t pos = 0; pos < sSize; ++pos) {
//             if (pos > endPos) {
//                 return {};
//             }
//             if (dp[pos].empty()) {
//                 continue;
//             }
//             for (string &word : wordDict) {
//                 uint32_t newPos = pos + word.size();
//                 if (newPos > sSize) {
//                     continue;
//                 }
//                 if (s.substr(pos, word.size()) == word) {
//                     for (auto &v : dp[pos]) {
//                         dp[newPos].push_back(v + 
//                             ((v == "") ? "" : " ") + word);
//                     }
//                 }
//                 endPos = (endPos < newPos) ? newPos : endPos;
//             }
//         }
//         return dp[sSize];
//     }

//     bool IfWordBreak(string s, vector<string>& wordDict) {
//         uint32_t sSize = s.size();
//         vector<bool> dp(sSize + 1, false);
//         dp[0] = true;

//         uint32_t endPos = 0;
//         for (uint32_t pos = 0; pos < sSize; ++pos) {
//             if (pos > endPos) {
//                 return {};
//             }
//             if (!dp[pos]) {
//                 continue;
//             }
//             for (string &word : wordDict) {
//                 uint32_t newPos = pos + word.size();
//                 if (newPos > sSize) {
//                     continue;
//                 }
//                 if (s.substr(pos, word.size()) == word) {
//                     dp[newPos] = true;
//                 }
//                 endPos = (endPos < newPos) ? newPos : endPos;
//             }
//         }
//         return dp[sSize];
//     }
// };

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        DFS(wordDict, s);
        return path[s];
    }

    vector<string> DFS(vector<string> &wordDict, string s)
    {
        if (path.count(s)) {
            return path[s];
        }

        if (s.empty()) {
            return {""};
        }
        
        for (auto &word : wordDict) {
            if (s.substr(0, word.size()) == word) {
                vector<string> tmp = DFS(wordDict,
                     s.substr(word.size()));
                
                for (auto &str : tmp) {
                    path[s].push_back(word + 
                    ((str == "") ? "" : " ") + str);
                }
            }
        }

        return path[s];
    }

private:
    unordered_map<string, vector<string>> path;
};
// @lc code=end

