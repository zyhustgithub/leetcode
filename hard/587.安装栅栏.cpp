/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */

// @lc code=start
vector<int> base;

int crossMul(const vector<int> &a, const vector<int> &b, const vector<int> &c)
{
    return (c[1] - b[1]) * (b[0] - a[0]) - (b[1] - a[1]) * (c[0] - b[0]);
}

int dis(vector<int> &a, vector<int> &b)
{
    int x = b[0] - a[0];
    int y = b[1] - a[1];
    return x * x + y * y;
}

bool cmp(vector<int> &b, vector<int> &c)
{
    int res = crossMul(base, b, c);
    if (res < 0) {
        return false;
    } else if (res > 0) {
        return true;
    } else {
        return dis(base, b) < dis(base, c);
    }
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() < 4) {
            return points;
        }
        int idx = 0;
        for (int pos = 1; pos < points.size(); ++pos) {
            if ((points[pos][0] < points[idx][0]) || ((points[pos][0] == points[idx][0]) &&
                (points[pos][1] < points[idx][1]))) {
                idx = pos;
            }
        }
        swap(points[0], points[idx]);
        base = points[0];
        sort(points.begin() + 1, points.end(), cmp);

        vector<vector<int>> st{points[0], points[1], points[2]};
        int top = 2;
        for (int i = 3; i < points.size(); ++i) {
            while (crossMul(st[top - 1], st[top], points[i]) < 0) {
                st.pop_back();
                --top;
            }
            st.push_back(points[i]);
            ++top;
        }

        top = points.size() - 1;
        while (crossMul(points[0], points[top - 1], points[top]) == 0) {
            st.push_back(points[top - 1]);
            --top;
        }

        return st;
    }
};
// @lc code=end

