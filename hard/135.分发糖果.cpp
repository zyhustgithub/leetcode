/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int member = ratings.size();
//         vector<int> cans(member, 1);

//         for (int i = 0; i < member - 1; ++i) {
//             if (ratings[i] < ratings[i + 1]) {
//                 cans[i + 1] = cans[i] + 1;
//             }
//         }

//         for (int i = member - 1; i > 0; --i) {
//             if (ratings[i] < ratings[i - 1]) {
//                 cans[i - 1] = max(cans[i - 1], cans[i] + 1);
//             }
//         }

//         int res = 0;
//         for (int n : cans) {
//             res += n;
//         }

//         return res;
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        int up = 0;
        int down = 0;
        int cans = 0;
        int oldState = 0;

        for (int i = 0; i + 1 < ratings.size(); ++i) {
            int newState = ((ratings[i + 1] > ratings[i]) ? 1 :
                ((ratings[i + 1] == ratings[i]) ? 0 : -1));
            if (((oldState == 1) && (newState == 0)) ||
                ((oldState == -1) && (newState >= 0))) {
                cans += (up) * (up + 1) / 2;
                cans += (down) * (down + 1) / 2;
                cans += max(up, down);
                up = 0;
                down = 0;
            }
            oldState = newState;
            if (newState == 1) {
                ++up;
            } else if (newState == -1) {
                ++down;
            } else {
                ++cans;
            }
        }

        cans += up * (up + 1) / 2 + down * (down + 1) / 2 +
            max(up, down) + 1;
        return cans;
    }
};
// @lc code=end

