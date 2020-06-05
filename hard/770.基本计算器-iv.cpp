/*
 * @lc app=leetcode.cn id=770 lang=cpp
 *
 * [770] 基本计算器 IV
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

bool Cmp(list<string> &a, list<string> &b)
{
    if (a.size() != b.size()) {
        return a.size() > b.size();
    } else {
        auto ita = a.begin();
        auto itb = b.begin();
        for (; ita != a.end(); ++ita, ++itb) {
            if (*ita != *itb) {
                return *ita < *itb;
            }
        }
    }
    return false;
}

class Poly {
public:
    Poly &Update(list<string> key, int val)
    {
        mp[key] += val;
        return *this;
    }

    Poly &Add(Poly &obj)
    {
        for (auto &m : obj.mp) {
            Update(m.first, m.second);
        }
        return *this;
    }

    Poly &Sub(Poly &obj)
    {
        for (auto &m : obj.mp) {
            Update(m.first, -m.second);
        }
        return *this;
    }

    Poly &Mul(Poly &obj)
    {
        Poly ans;
        for (auto &l : mp) {
            for (auto &r : obj.mp) {
                list<string> newKey{l.first};
                for (auto &s : r.first) {
                    newKey.push_back(s);
                }
                newKey.sort();
                ans.Update(newKey, l.second * r.second);
            }
        }
        return (*this = ans);
    }

    Poly &Evaluate(unordered_map<string, int> &evalMp)
    {
        Poly ans;
        for (auto m : mp) {
            list<string> newKey;
            int num = m.second;
            for (auto &s : m.first) {
                if (evalMp.count(s) != 0) {
                    num *= evalMp[s];
                } else {
                    newKey.push_back(s);
                }
            }
            ans.Update(newKey, num);
        }
        return (*this = ans);
    }

    vector<string> ToVector()
    {
        vector<string> res;
        vector<list<string>> keys;
        for (auto &m : mp) {
            if (m.second == 0) {
                continue;
            }
            keys.push_back(m.first);
        }

        sort(keys.begin(), keys.end(), Cmp);

        for (auto &key : keys) {
            string str = to_string(mp[key]);
            for (auto &s : key) {
                str += '*' + s;
            }

            res.push_back(str);
        }

        return res;
    }

public:
    map<list<string>, int> mp;
};

class Solution {
public:
    Poly MakePoly(string expr)
    {
        Poly res;
        list<string> key;
        if (isdigit(expr[0])) {
            res.mp[key] = stoul(expr);
        } else {
            key.push_back(expr);
            res.mp[key] = 1;
        }

        return res;
    }

    Poly Combine(Poly &left, Poly &right, char oper)
    {
        if (oper == '+') {
            return left.Add(right);
        } else if (oper == '-') {
            return left.Sub(right);
        } else {
            return left.Mul(right);
        }
    }

    Poly Parse(string expr)
    {
        vector<Poly> dp;
        vector<char> symbols;
        for (int pos = 0; pos < expr.size(); ++pos) {
            if (expr[pos] == '(') {
                int cnt = 0;
                int start = pos + 1;
                while (pos < expr.size()) {
                    if (expr[pos] == '(') {
                        ++cnt;
                    } else if (expr[pos] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) {
                        break;
                    }
                    ++pos;
                }
                dp.push_back(Parse(expr.substr(start, pos - start)));
            } else if (expr[pos] != ' ') {
                if ((expr[pos] == '*') || (expr[pos] == '+') || (expr[pos] == '-')) {
                    symbols.push_back(expr[pos]);
                    continue;
                }
                int start = pos;
                while ((pos < expr.size()) && (expr[pos] != ' ')) {
                    ++pos;
                }

                dp.push_back(MakePoly(expr.substr(start, pos - start)));
            }
        }

        for (int idx = symbols.size() - 1; idx >= 0; --idx) {
            if (symbols[idx] == '*') {
                dp[idx] = Combine(dp[idx], dp[idx + 1], '*');
                dp.erase(dp.begin() + idx + 1);
                symbols.erase(symbols.begin() + idx);
            }
        }

        if (dp.empty()) {
            return {};
        }

        for (int idx = 0; idx < symbols.size(); ++idx) {
            dp[0] = Combine(dp[0], dp[1], symbols[idx]);
            dp.erase(dp.begin() + 1);
        }

        return dp[0];
    }

    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        for (int pos = 0; pos < evalvars.size(); ++pos) {
            evalMp[evalvars[pos]] = evalints[pos];
        }

        return Parse(expression).Evaluate(evalMp).ToVector();
    }

private:
    unordered_map<string, int> evalMp;
};
// @lc code=end

