/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPoints = 0;
        int nums = points.size();
        if (nums < 3) {
            return nums;
        }
        for (int i = 0; i < nums - 1; ++i) {
            int sames = 1;
            for (int j = i + 1; j < nums; ++j) {
                int count = 0;
                if (points[i] == points[j]) {
                    ++sames;
                } else {
                    ++count;
                    for (int k = j + 1; k < nums; ++k) {
                        if (IsOneLine(points[i], points[j], points[k])) {
                            ++count;
                        }
                    }
                }
                maxPoints = max(maxPoints, count + sames);
                if (maxPoints > (nums / 2 + 1)) {
                    return maxPoints;
                }
            }
        }
        return maxPoints;
    }

    bool IsOneLine(vector<int> &lOri, vector<int> &rOri, vector<int> &pos)
    {
        if ((long)(rOri[1] - lOri[1]) * (long)(pos[0] - lOri[0]) ==
            (long)(pos[1] - lOri[1]) * (long)(rOri[0] - lOri[0])) {
            return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int maxPoints = 0;
//         int nums = points.size();
//         if (nums < 3) {
//             return nums;
//         }
//         for (int i = 0; i < nums - 1; ++i) {
//             int sames = 1;
//             for (int j = i + 1; j < nums; ++j) {
//                 string slope = StrSlope(points[i], points[j]);
                
//                 int count = 0;
//                 if (slope == to_string(points[i][0]) + "," + to_string(points[i][1])) {
//                     ++sames;
//                 } else {
//                     if (visit.count(slope)) {
//                         continue;
//                     }
//                     ++count;
//                     for (int k = j + 1; k < nums; ++k) {
//                         if (IsOneLine(slope, points[i], points[k])) {
//                             ++count;
//                         }
//                     }
//                 }
//                 visit.insert(slope);
//                 maxPoints = max(maxPoints, count + sames);
//                 if (maxPoints > (nums / 2 + 1)) {
//                     return maxPoints;
//                 }
//             }
//         }
//         return maxPoints;
//     }

//     bool IsOneLine(string &slope, vector<int> &ori, vector<int> &pos)
//     {
//         if ((pos[0] == ori[0]) && (pos[1] == ori[1])) {
//             return true;
//         }
//         string curSlope = StrSlope(ori, pos);
//         if (slope == curSlope) {
//             return true;
//         }
//         return false;
//     }

//     string StrSlope(vector<int> &l, vector<int> &r)
//     {
//         int a = l[1] - r[1];
//         int b = l[0] - r[0];
//         if ((a == 0) && (b != 0)) {
//             return "0/" + to_string(l[1]);
//         }

//         if ((a != 0) && (b == 0)) {
//             return to_string(l[0]) + "/0";
//         }

//         if ((a == 0) && (b == 0)) {
//             return to_string(l[0]) + "," + to_string(l[1]);
//         }

//         int gcd = GCD(a, b);
//         a = a / gcd;
//         b = b / gcd;
//         return to_string(a) + "/" + to_string(b);
//     }

//     int GCD(int a, int b)
//     {
//         if (b == 0) {
//             return a;
//         }
//         return GCD(b, a % b);
//     }

// private:
//     unordered_set<string> visit;
// };
// @lc code=end

