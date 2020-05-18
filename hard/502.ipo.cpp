/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> maxQue;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> minQue;

        for (int idx = 0; idx < Profits.size(); ++idx) {
            minQue.push({Capital[idx], Profits[idx]});
        }
        int res = W;
        for (int idx = 0; idx < k; ++idx) {
            while (!minQue.empty() && res >= minQue.top().first) {
                maxQue.push(minQue.top().second);
                minQue.pop();
            }

            if (!maxQue.empty()) {
                res += maxQue.top();
                maxQue.pop();
            } else {
                break;
            }
        }

        return res;
    }
};
// @lc code=end

