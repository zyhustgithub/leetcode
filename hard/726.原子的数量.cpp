/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, long> mp = DFS(formula);
        string res;
        for (auto it : mp) {
            res += it.first;
            res += (it.second > 1) ? to_string(it.second) : "";
        }

        return res;
    }

    map<string, long> DFS(string formula)
    {
        map<string, long> mp;
        if (formula.empty()) {
            return mp;
        }

        string strKey("");
        long count = 0;
        int idx = 0;
        while (idx < formula.size()) {
            if (formula[idx] != '(') {
                if (WhichType(formula[idx]) > 0) {
                    if ((WhichType(formula[idx]) == 2) && !strKey.empty()) {
                        mp[strKey] += max(count, 1L);
                        strKey.resize(0);
                        strKey += formula[idx];
                        count = 0;
                    } else {
                        strKey += formula[idx];
                    }
                } else if (WhichType(formula[idx]) == 0) {
                    count *= 10;
                    count += (formula[idx] - '0');
                }
                ++idx;
            } else {
                if (!strKey.empty()) {
                    mp[strKey] += max(count, 1L);
                    strKey.resize(0);
                    count = 0;
                }

                int tmpNum = 1;
                int pre = idx;
                int post = pre;

                while (tmpNum != 0) {
                    ++post;
                    if (formula[post] == '(') {
                        ++tmpNum;
                    } else if(formula[post] == ')') {
                        --tmpNum;
                    }
                }

                // cout << formula.substr(pre + 1, post - pre - 1) << endl;
                map<string, long> tmpMp = DFS(formula.substr(pre + 1, post - pre - 1));
                idx = post + 1;
                while ((idx < formula.size()) && (WhichType(formula[idx]) == 0)) {
                    count *= 10;
                    count += (formula[idx] - '0');
                    ++idx;
                }

                for (auto &it : tmpMp) {
                    mp[it.first] += max(it.second, 1L) * max(count, 1L);
                }
                count = 0;
            }
        }
        if (!strKey.empty()) {
            mp[strKey] += max(count, 1L);
        }
        return mp;
    }

    int WhichType(char ch)
    {
        if ((ch >= 'A') && (ch <= 'Z')) {
            return 2;
        }

        if ((ch >= 'a') && (ch <= 'z')) {
            return 1;
        }

        if ((ch >= '0') && (ch <= '9')) {
            return 0;
        }

        return -1;
    }
};
// @lc code=end

