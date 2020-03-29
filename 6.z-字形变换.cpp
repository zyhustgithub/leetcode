/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string retStr("");
        int strLen = s.size();
        int gap = 2 * numRows - 2;
        for (int row = 0; row < numRows; ++row) {
            for (int idx = row; idx < strLen; idx += gap) {
                retStr += s[idx];
                int tmp = idx + gap - 2 * row;
                if ((row != 0) && (row != numRows - 1) && (tmp < strLen)) {
                    retStr += s[tmp];
                }
            }
        }
        return retStr;
    }
};

class Solution1 {
public:
	string convert(string s, int numRows) {

		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {// 当前行curRow为0或numRows -1时，箭头发生反向转折
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) {// 从上到下遍历行
			ret += row;
		}

		return ret;
	}
};
// @lc code=end

