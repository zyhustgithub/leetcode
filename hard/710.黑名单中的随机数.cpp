/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
public:
    Solution(int N, vector<int>& blacklist) : num(N), blackList(blacklist)
    {
        sort(blackList.begin(), blackList.end());
    }

    int GetNum(int idx)
    {
        if (blackList.empty()) {
            return idx;
        }
        int left = 0;
        int right = blackList.size() - 1;
        while (left < right) {
            int mid = (right + left + 1) / 2;
            if (blackList[mid] - mid > idx) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return (blackList[left] - left <= idx) ? left + idx + 1 : idx;
    }
    
    int pick() {
        return GetNum(rand() % (num - blackList.size()));
    }

private:
    vector<int> &blackList;
    int num;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

