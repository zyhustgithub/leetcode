/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        if (res.empty()) {
            res.push_back({val, val});
            return;
        }

        if (val > res.back()[1] + 1) {
            res.push_back({val, val});
            return;
        }

        if (val == res.back()[1] + 1) {
            res.back()[1] = val;
            return;
        }

        int left = 0;
        int right = res.size() - 1;
        int mid;
        while (left < right) {
            mid = (right + left + 1) / 2;
            if (res[mid][0] > val) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        if ((left == 0) && (val == res[0][0] - 1)) {
            res[0][0] = val;
        } else if ((left == 0) && (val < res[0][0] - 1)) {
            res.insert(res.begin(), {val, val});
        } else if ((left < res.size() - 1) && (val >= res[left][0])) {
            if ((res[left + 1][0] == res[left][1] + 2) && (val == res[left][1] + 1)) {
                res[left][1] = res[left + 1][1];
                res.erase(res.begin() + left + 1);
            } else if (val == res[left][1] + 1) {
                res[left][1] = val;
            } else if (val == res[left + 1][0] - 1) {
                res[left + 1][0] = val;
            } else if (val > res[left][1] + 1) {
                res.insert(res.begin() + left + 1, {val, val});
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return res;
    }

private:
    vector<vector<int>> res;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

