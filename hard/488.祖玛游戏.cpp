/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
class Solution {
public:
    int findMinStep(string board, string hand) {
        for (auto ch: hand) {
            ++mp[ch];
        }

        int res = INT_MAX;
        DFS(board, 0, res);
        return (res == INT_MAX) ? -1 : res;
    }

    void DFS(string &board, int curNum, int &res)
    {
        if (board.empty()) {
            res = min(curNum, res);
            return;
        }

        if (curNum >= res) {
            return;
        }

        for (int pos = 0; pos < board.size(); ++pos) {
            int pre = pos;
            while ((pos + 1 < board.size()) && (board[pos] == board[pos + 1])) {
                ++pos;
            }

            int num = max(0, 3 - (pos - pre + 1));

            if (mp[board[pre]] >= num) {
                mp[board[pre]] -= num;
                string tmp = board.substr(0, pre);
                tmp += board.substr(pos + 1, board.size() - pos);
                DFS(tmp, curNum + num, res);
                mp[board[pre]] += num;
            }
        }
    }

private:
    unordered_map<char, int> mp;
};
// @lc code=end

