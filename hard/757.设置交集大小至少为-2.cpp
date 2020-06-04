/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757]  设置交集大小至少为2
 */

// @lc code=start
bool Cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] > b[1];
    }
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Cmp);
        int arrSize = intervals.size();
        vector<int> count(arrSize, 2);

        int ans = 0;
        // set<int> res;
        while (!intervals.empty()) {
            int val = intervals.back()[0];
            int cnt = count.back();
            intervals.pop_back();
            count.pop_back();
            for (int num = val + cnt - 1; num >= val; --num) {
                for (int idx = 0; idx < intervals.size(); ++idx) {
                    if ((intervals[idx][1] >= num) && (count[idx] > 0)) {
                        --count[idx];
                    }
                }
                ++ans;
                // res.insert(num);
            }
        }

        // for (auto n : res) {
        //     cout << n;
        // }
        return ans;
    }
};
// @lc code=end

