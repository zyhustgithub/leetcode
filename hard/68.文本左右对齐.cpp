/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int pos = 0;
        int vecSize = words.size();
        vector<string> ans;
        string tmpStr = "";
        int pre = 0;
        int post = 0;
        while (pos < vecSize) {
            if (tmpStr.size() + words[pos].size() > maxWidth) {
                tmpStr.erase(tmpStr.size() - 1, 1);
                BuildLine(words, pre, post, tmpStr, maxWidth - tmpStr.size());
                ans.push_back(tmpStr);
                tmpStr = "";
                pre = pos;
            }
            tmpStr += words[pos];
            tmpStr += " ";
            post = pos;
            ++pos;
        }
        if (pre <= post) {
            tmpStr.erase(tmpStr.size() - 1, 1);
            ans.push_back(tmpStr + string(maxWidth - tmpStr.size(), ' '));
        }
        return ans;
    }

    void BuildLine(vector<string> &words, int pre, int post, string &str,
        int spaceNum)
    {
        int wNum = post - pre;
        int pos = str.size();
        if (wNum == 0) {
            str.insert(pos, string(spaceNum, ' '));
        }
        for (int i = post; i > pre; --i) {
            int spaces = spaceNum / wNum;
            pos -= words[i].size() + 1;
            str.insert(pos, string(spaces, ' '));
            spaceNum -= spaces;
            --wNum;
        }
    }
};
// @lc code=end

