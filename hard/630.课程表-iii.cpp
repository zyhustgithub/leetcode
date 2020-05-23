/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
bool Cmp(vector<int> &l, vector<int> &r)
{
    return l[1] < r[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), Cmp);
        priority_queue<int, vector<int>, less<int>> pq;
        
        int sum = 0;
        for (auto &vec : courses) {
            if (sum + vec[0] > vec[1]) {
                if (!pq.empty() && (sum - pq.top() + vec[0] <= vec[1]) &&
                    (vec[0] < pq.top())) {
                    sum += vec[0] - pq.top();
                    pq.pop();
                    pq.push(vec[0]);
                }
            } else {
                pq.push(vec[0]);
                sum += vec[0];
            }
        }

        return pq.size();
    }
};
// @lc code=end

