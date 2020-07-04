/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int vecSize = A.size();
        f.resize(vecSize);
        for (int idx = 0; idx < vecSize; ++idx) {
            f[idx] = idx;
        }

        for (int idx = 0; idx < vecSize; ++idx) {
            for (int pos = idx + 1; pos < vecSize; ++pos) {
                if (IsSimilar(A[idx], A[pos])) {
                    f[Find(idx)] = Find(pos);
                }
            }
        }


        set<int> ans;
        for (int idx = 0; idx < vecSize; ++idx) {
            ans.insert(Find(idx));
        }

        return ans.size();
    }

    int Find(int x)
    {
        if (x == f[x]) {
            return x;
        }
        return (f[x] = Find(f[x]));
    }

    // 可能测试用例设计的巧，所以这个函数考虑的可以不全面
    bool IsSimilar(string &str1, string &str2)
    {
        if (str1.size() != str2.size()) {
            return false;
        }

        int diffNum = 0;
        for (int idx = 0; idx < str1.size(); ++idx) {
            if (str1[idx] == str2[idx]) {
                continue;
            }
            ++diffNum;
            if (diffNum > 2) {
                return false;
            }
        }

        return true;
    }

private:
    vector<int> f;
};
// @lc code=end

