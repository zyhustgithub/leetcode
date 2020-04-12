/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Size = word1.size();
        int word2Size = word2.size();
        int ops[word1Size + 1][word2Size + 1];
        ops[0][0] = 0;

        for (int pos = 1; pos <= word1Size; ++pos) {
            ops[pos][0] = pos;
        }
        for (int pos = 1; pos <= word2Size; ++pos) {
            ops[0][pos] = pos;
        }

        for (int pos1 = 1; pos1 <= word1Size; ++pos1) {
            for (int pos2 = 1; pos2 <= word2Size; ++pos2) {
                ops[pos1][pos2] = min(ops[pos1 - 1][pos2] + 1,
                    ops[pos1][pos2 - 1] + 1);
                ops[pos1][pos2] = min(ops[pos1][pos2],
                    ops[pos1 - 1][pos2 - 1] + int(word1[pos1 - 1] != word2[pos2 - 1]));
            }
        }
        return ops[word1Size][word2Size];
    }
};
// @lc code=end

