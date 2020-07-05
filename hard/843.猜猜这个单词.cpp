/*
 * @lc app=leetcode.cn id=843 lang=cpp
 *
 * [843] 猜猜这个单词
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <set>
#include <assert.h>

using namespace std;

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int wordlistSize = wordlist.size();
        vector<vector<int>> simVec(wordlistSize, vector<int>(wordlistSize, 0));
        for (int idx = 0; idx < wordlistSize; ++idx) {
            simVec[idx][idx] = 6;
            for (int pos = idx + 1; pos < wordlistSize; ++pos) {
                simVec[idx][pos] = simVec[pos][idx] = Similar(wordlist[idx], wordlist[pos]);
            }
        }

        vector<bool> cans(wordlistSize, true);
        while (true) {
            int idx = GetMaxSimilarPos(simVec, cans);
            cout << idx << endl;
            int count = master.guess(wordlist[idx]);
            if (count == 6) {
                return;
            }
            for (int pos = 0; pos < wordlistSize; ++pos) {
                if ((cans[pos]) && (simVec[pos][idx] != count)) {
                    cans[pos] = false;
                }
            }
        }
    }

    int GetMaxSimilarPos(const vector<vector<int>> &simVec, const vector<bool> &cans)
    {
        // assert(simVec.size() == cans.size());
        int vecSize = simVec.size();
        int maxCnt = INT_MAX;
        int maxPos = -1;
        for (int idx = 0; idx < vecSize; ++idx) {
            if (!cans[idx]) {
                continue;
            }
            
            vector<int> cnts(6, 0);
            for (int pos = 0; pos < vecSize; ++pos) {
                if ((pos == idx) || (!cans[pos])) {
                    continue;
                }
                ++cnts[simVec[idx][pos]];
            }

            int curCnt = *max_element(cnts.begin(), cnts.end());
            if (maxCnt > curCnt) {
                maxCnt = curCnt;
                maxPos = idx;
            }
        }

        return maxPos;
    }

    int Similar(string &str1, string &str2)
    {
        // assert(str1.size() == str2.size());
        int count = 0;
        for (int idx = 0; idx < str1.size(); ++idx) {
            count += (str1[idx] == str2[idx]);
        }

        return count;
    }
};
// @lc code=end

