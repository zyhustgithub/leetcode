/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node {
    string str;
    int steps;

    explicit Node(string &s) : str(s), steps(0) {}
    explicit Node(string &s, int _steps) : str(s), steps(_steps) {}
};

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A.size() != B.size()) {
            return -1;
        }

        unordered_set<string> seen{A};
        queue<Node> q;
        q.push(std::move(Node(A)));
        while (!q.empty()) {
            Node cur = q.front();
            q.pop();
            if (cur.str == B) {
                return cur.steps;
            }

            vector<string> similar;
            FindSimilar(cur.str, B, similar);
            for (auto &s : similar) {
                if (seen.count(s) == 0) {
                    seen.insert(s);
                    q.push(Node(s, cur.steps + 1));
                }
            }
        }

        return -1;
    }

    void FindSimilar(string &srcStr, string &dstStr, vector<string> &res)
    {
        if (srcStr.size() != dstStr.size()) {
            return;
        }

        int pos = 0;
        while (pos < srcStr.size()) {
            if (srcStr[pos] != dstStr[pos]) {
                break;
            }
            ++pos;
        }

        for (int idx = pos; idx < srcStr.size(); ++idx) {
            if (srcStr[idx] == dstStr[pos]) {
                string tmp(srcStr);
                tmp[idx] = tmp[pos];
                tmp[pos] = dstStr[pos];
                res.push_back(std::move(tmp));
            }
        }
    }
};
// @lc code=end

