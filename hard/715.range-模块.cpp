/*
 * @lc app=leetcode.cn id=715 lang=cpp
 *
 * [715] Range 模块
 */

// @lc code=start
class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        for (auto it = mp.lower_bound(left); (it != mp.end()) &&
            (it->second <= right); ++it) {
            q.push(it);
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            left = min(left, it->second);
            right = max(right, it->first);
            mp.erase(it);
        }
        mp[right] = left;
    }
    
    bool queryRange(int left, int right) {
        auto it = mp.lower_bound(left);
        return (it != mp.end()) && (it->second <= left) && (it->first >= right);
    }
    
    void removeRange(int left, int right) {
        for (auto it = mp.lower_bound(left); (it != mp.end()) &&
            (it->second <= right); ++it) {
            q.push(it);
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int oldLeft = it->second;
            int oldRight = it->first;
            mp.erase(it);
            if (left > oldLeft) {
                mp[left] = oldLeft;
            }
            if (right < oldRight) {
                mp[oldRight] = right;
            }
        }
    }

private:
    map<int, int> mp;
    queue<map<int, int>::iterator> q;
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

