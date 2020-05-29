/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */

// @lc code=start
// typedef vector<int>::iterator ITER_TYPE;

// struct Cmp {
//     bool operator()(ITER_TYPE &l, ITER_TYPE &r) const
//     {
//         return *l > *r;
//     }
// };

// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         priority_queue<ITER_TYPE, vector<ITER_TYPE>, Cmp> pq;
//         set<ITER_TYPE> ends;

//         int maxNum = INT_MIN;
//         for (auto &vec : nums) {
//             if (maxNum < *vec.begin()) {
//                 maxNum = *vec.begin();
//             }
//             pq.push(vec.begin());
//             ends.insert(vec.end());
//         }

//         int left = 0;
//         int right = INT_MAX;
//         int curLeft;
//         int curRight;
//         while (true) {
//             curLeft = *pq.top();
//             curRight = maxNum;
//             if ((right - left) > (curRight - curLeft)) {
//                 left = curLeft;
//                 right = curRight;
//             }
//             ITER_TYPE tmp = pq.top();
//             pq.pop();
//             if (ends.count(++tmp) != 0) {
//                 break;
//             }
//             if (maxNum < *tmp) {
//                 maxNum = *tmp;
//             }
//             pq.push(tmp);
//         }

//         return {left, right};
//     }
// };

typedef vector<int> *DATA_TYPE;
struct Cmp {
    bool operator()(DATA_TYPE &l, DATA_TYPE &r) const
    {
        return l->front() > r->front();
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<DATA_TYPE, vector<DATA_TYPE>, Cmp> pq;

        int maxNum = INT_MIN;
        for (auto &vec : nums) {
            if (maxNum < *vec.begin()) {
                maxNum = *vec.begin();
            }
            pq.push(&vec);
        }

        int left = 0;
        int right = INT_MAX;
        int curLeft;
        int curRight;
        while (true) {
            curLeft = pq.top()->front();
            curRight = maxNum;
            if ((right - left) > (curRight - curLeft)) {
                left = curLeft;
                right = curRight;
            }
            DATA_TYPE tmp = pq.top();
            pq.pop();
            tmp->erase(tmp->begin());
            if (tmp->empty()) {
                break;
            }
            if (maxNum < tmp->front()) {
                maxNum = tmp->front();
            }
            pq.push(tmp);
        }

        return {left, right};
    }
};
// @lc code=end

