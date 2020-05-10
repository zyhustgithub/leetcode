/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
struct Data {
    int x;
    int y;
    int h;

    bool operator<(const Data &obj) const
    {
        if (x != obj.x) {
            return x < obj.x;
        }
        if (h * obj.h < 0) {
            return (h < 0) ? true : false;
        }
        return tie(y, h) < tie(obj.y, obj.h);
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<Data> lines;
        for (auto &vec: rectangles) {
            lines.push_back({vec[0], vec[1], vec[3] - vec[1]});
            lines.push_back({vec[2], vec[1], vec[1] - vec[3]});
        }
        sort(lines.begin(), lines.end());
        for (auto &d: lines) {
            cout << d.x << "," << d.y << "," << d.h << endl;
        }
        int height = 0;
        int axis = lines[0].x;
        int low = lines[0].y;
        for (auto &d: lines) {
            if (d.x != axis) {
                break;
            }
            height += d.h;
        }
        int high = low + height;
        cout << low << " " << high << " " << height;

        int curHeight = 0;
        int cury = INT_MIN;
        for (auto &d: lines) {
            if (axis != d.x) {
                if (curHeight != height) {
                    return false;
                }
                if ((d.y < low) || (d.y + d.h > high)) {
                    return false;
                }
                axis = d.x;
                cury = d.y;
            }

            if (d.y < cury) {
                return false;
            }
            if (d.h > 0) {
                cury = d.y + d.h;
            }

            curHeight += d.h;
        }
        return (curHeight == 0) ? true : false;
    }
};
// @lc code=end

