/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<int> vecIdx(quality.size(), 0);
        for (int idx = 0; idx < quality.size(); ++idx) {
            vecIdx[idx] = idx;
        }

        sort(vecIdx.begin(), vecIdx.end(), [&quality, &wage](int a, int b) -> bool {
            if (wage[a] * quality[b] == wage[b] * quality[a]) {
                return quality[a] > quality[b];
            }
            return wage[a] * quality[b] < wage[b] * quality[a];
        });
        
        priority_queue<int, vector<int>, less<int>> pq;
        long sum = 0;
        for (int idx = 0; idx < K; ++idx) {
            pq.push(quality[vecIdx[idx]]);
            sum += quality[vecIdx[idx]];
        }

        double ans = static_cast<double>(sum * wage[vecIdx[K - 1]]) / quality[vecIdx[K - 1]];
        for (int idx = K; idx < quality.size(); ++idx) {
            int topNum = pq.top();
            pq.pop();
            pq.push(quality[vecIdx[idx]]);
            sum = sum - topNum + quality[vecIdx[idx]];
            double tmp = static_cast<double>(sum * wage[vecIdx[idx]]) / quality[vecIdx[idx]];
            ans = min(ans, tmp);
        }

        return ans;
    }
};

#if 0
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> quality = {14,56,59,89,39,26,86,76,3,36};
    vector<int> wage = {90,217,301,202,294,445,473,245,415,487};
    cout << s.mincostToHireWorkers(quality, wage, 2) << endl;
}
#endif
// @lc code=end
