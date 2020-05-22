/*
 * @lc app=leetcode.cn id=591 lang=cpp
 *
 * [591] 标签验证器
 */

// @lc code=start
class Solution {
public:
    bool isValid(string code) {
        if ((code[0] != '<') || (code.back() != '>') || (code.size() < 7)) {
            return false;
        }

        stack<string> st;

        for (int pos = 0; pos < code.size(); ++pos) {
            if (code[pos] == '<') {
                if (pos >= code.size() - 2) {
                    return false;
                }

                if (code[pos + 1] == '!') {
                    string cdataHead = code.substr(pos, 9);
                    int endPos = code.find("]]>", pos + 9);
                    if ((cdataHead != "<![CDATA[") || (endPos == string::npos) ||
                        (pos + 15 >= code.size()) || st.empty()) {
                        return false;
                    }
                    pos = endPos + 2;
                } else {
                    bool flag = (code[pos + 1] == '/');
                    pos += flag;
                    string tagName("");
                    ++pos;
                    while ((pos < code.size()) && (code[pos] != '>')) {
                        char ch = code[pos];
                        if ((ch >= 'A') && (ch <= 'Z')) {
                            tagName += code[pos];
                        } else {
                            return false;
                        }
                        ++pos;
                    }

                    if ((tagName.size() < 1) || (tagName.size() > 9)) {
                        return false;
                    }

                    if (flag) {
                        if (st.empty() || (tagName != st.top())) {
                            return false;
                        }
                        st.pop();
                        if (st.empty() && (pos != code.size() - 1)) {
                            return false;
                        }
                    } else {
                        st.push(tagName);
                    }
                }
            }
        }

        return st.empty();
    }
};
// @lc code=end

