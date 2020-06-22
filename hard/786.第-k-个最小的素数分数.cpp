/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
// struct Node {
//     double val;
//     int start;
//     int end;
//     bool operator<(const Node &obj) const
//     {
//         return val < obj.val;
//     }
// };

// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
//         set<Node> pq;
//         for (int idx = A.size() - 1; idx >= 0; --idx) {
//             pq.insert({(double)A[0] / (double)A[idx], 0, idx});
//         }

//         while (--K) {
//             Node cur = *pq.begin();
//             pq.erase(pq.begin());
//             // cout << A[cur.start] << " " << A[cur.end] << endl;
//             int idx = cur.start + 1;
//             if (idx < cur.end) {
//                 pq.insert({(double)A[idx] / (double)A[cur.end], idx, cur.end});
//             }
//         }

//         return {A[pq.begin()->start], A[pq.begin()->end]};
//     }
// };

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int aSize = A.size();
        double left = 0.0;
        double right = 1.0;
        int p = 0;
        int q = 1;
        int cnt = 0;

        while (true) {
            double mid = (left + right) / 2.0;
            cnt = 0;
            p = 0;
            // end 在循环里定义才能不超时
            for (int idx = 0, end = idx + 1; idx < aSize - 1; ++idx) {
                while ((end < aSize) && (A[idx] > A[end] * mid)) {
                    ++end;
                }
                cnt += aSize - end;

                if ((end < aSize) && (p * A[end] < q * A[idx])) {
                    p = A[idx];
                    q = A[end];
                }
            }

            if (cnt == K) {
                break;
            } else if (cnt < K) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return {p, q};
    }
};

// @lc code=end

