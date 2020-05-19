/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
// class Solution {
// public:
//     int findRotateSteps(string ring, string key) {
//         int ringSize = ring.size();
//         unordered_map<char, vector<int>> mp;
//         for (int idx = 0; idx < ringSize; ++idx) {
//             mp[ring[idx]].push_back(idx);
//         }

//         vector<int> dp(ringSize, 0x3f3f3f);
//         dp[0] = 0;
//         vector<int> prev{0};
//         for (auto ch : key) {
//             vector<int> tmp(ringSize, 0x3f3f3f);
//             for (int pre : prev) {
//                 for (int post : mp[ch]) {
//                     int dis = abs(post - pre);
//                     tmp[post] = min(tmp[post], dp[pre] + 1 + min(dis, ringSize - dis));
//                 }
//             }
//             prev = mp[ch];
//             dp = tmp;
//         }

//         return *min_element(dp.begin(), dp.end());
//     }
// };

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringSize = ring.size();
        unordered_map<char, vector<int>> mp;
        for (int idx = 0; idx < ringSize; ++idx) {
            mp[ring[idx]].push_back(idx);
        }

        vector<int> dp(ringSize, 0x3f3f3f);
        dp[0] = 0;
        vector<int> prev{0};
        for (auto ch : key) {
            if (ch == ring[prev[0]]) {
                for (auto pre : prev) {
                    ++dp[pre];
                }
            } else {
                for (int pre : prev) {
                    for (int post : mp[ch]) {
                        int dis = abs(post - pre);
                        dp[post] = min(dp[post], dp[pre] + 1 + min(dis, ringSize - dis));
                    }
                    dp[pre] = 0X3f3f3f;
                }
            }
            prev = mp[ch];
        }

        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end

