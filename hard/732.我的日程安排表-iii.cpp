/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start
class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        ++mp[start];
        --mp[end];

        int res = 0;
        int calendars = 0;
        for (auto &it : mp) {
            calendars += it.second;
            if (calendars > res) {
                res = calendars;
            }
        }

        return res;
    }

private:
    map<int, int> mp;
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

