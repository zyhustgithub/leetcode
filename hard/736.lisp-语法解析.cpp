/*
 * @lc app=leetcode.cn id=736 lang=cpp
 *
 * [736] Lisp 语法解析
 */

// @lc code=start
constexpr int INF = 0x3f3f3f;

class Solution {
public:
    int evaluate(string expression) {
        vector<string> cmds;
        ParseStrCmd(expression, cmds);
        // for (auto &s : cmds) {
        //     cout << s << "#";
        // }
        // cout << endl;

        map<string, int> pVar;
        int res = 0;

        if (cmds[0] == "let") {
            int i = 1;
            for (; i + 1 < cmds.size(); i += 2) {
                string &l = cmds[i];
                string &r = cmds[i + 1];

                if (pVar.count(l) == 0) {
                    if (mVar.count(l) != 0) {
                        pVar[l] = mVar[l];
                    } // else {
                    //     pVar[l] = INF;
                    // }
                }

                if (r[0] == '(') {
                    mVar[l] = evaluate(r);
                } else if (((r[0] >= '0') && (r[0] <= '9')) || (r[0] == '-')) {
                    mVar[l] = stoi(r);
                } else {
                    mVar[l] = mVar[r];
                }
            }

            if (cmds[i][0] == '(') {
                res = evaluate(cmds[i]);
            } else {
                res = (mVar.count(cmds[i]) == 0) ? stoi(cmds[i]) : mVar[cmds[i]];
            }
        } else {
            int l = 0;
            if (cmds[1][0] == '(') {
                l = evaluate(cmds[1]);
            } else {
                l = (mVar.count(cmds[1]) != 0) ? mVar[cmds[1]] : stoi(cmds[1]);
            }

            int r = 0;
            if (cmds[2][0] == '(') {
                r = evaluate(cmds[2]);
            } else {
                r = (mVar.count(cmds[2]) != 0) ? mVar[cmds[2]] : stoi(cmds[2]);
            }
            cout << l << "&" << r << endl;
            res = (cmds[0] == "add") ? (l + r) : (l * r);
        }

        for (auto it = pVar.begin(); it != pVar.end(); ++it) {
            // if (it->second == INF) {
            //     pVar.erase(it);
            // } else {
                mVar[it->first] = it->second;
            // }
        }
        
        return res;
    }

    void ParseStrCmd(string &strCmd, vector<string> &cmds)
    {
        int cnt = 0;
        int start = (strCmd[0] == '(') ? 1 : 0;
        for (int i = start; i < strCmd.size(); ++i) {
            if ((cnt == 0) && ((strCmd[i] == ' ') || (strCmd[i] == ')'))) {
                cmds.push_back(strCmd.substr(start, i - start));
                start = i + 1;
            }

            if (strCmd[i] == '(') {
                ++cnt;
            } else if (strCmd[i] == ')') {
                --cnt;
            }
        }
    }

private:
    map<string, int> mVar;
};
// @lc code=end

