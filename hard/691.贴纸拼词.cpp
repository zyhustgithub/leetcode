/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

// @lc code=start
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int> dp((1 << target.size()), INT_MAX);
        vector<vector<int>> fps(stickers.size(), vector<int>(26, 0));
        vector<vector<int>> cans(26);

        for (int idx = 0; idx < stickers.size(); ++idx) {
            for (auto ch : stickers[idx]) {
                ++fps[idx][ch - 'a'];
                if (cans[ch - 'a'].empty() || cans[ch - 'a'].back() != idx) {
                    cans[ch - 'a'].push_back(idx);
                }
            }
        }

        dp[0] = 0;

        for (int idx = 0; idx < (1 << target.size()) - 1; ++idx) {
            if (dp[idx] == INT_MAX) {
                continue;
            }

            int sel = 0;
            for (int pos = 0; pos < target.size(); ++pos) {
                sel = pos;
                if ((idx & (1 << pos)) == 0) {
                    break;
                }
            }

            for (auto wordIdx : cans[target[sel] - 'a']) {
                vector<int> tmpVec(fps[wordIdx]);
                int tmpNum = idx;
                for (int pos = 0; pos < target.size(); ++pos) {
                    if (idx & (1 << pos)) {
                        continue;
                    }

                    if (tmpVec[target[pos] - 'a'] > 0) {
                        tmpNum += (1 << pos);
                        --tmpVec[target[pos] - 'a'];
                    }
                }

                dp[tmpNum] = min(dp[idx] + 1, dp[tmpNum]);
            }
        }

        return (dp[(1 << target.size()) - 1] == INT_MAX) ? -1 : dp[(1 << target.size()) - 1];
    }
};
// @lc code=end

