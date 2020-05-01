/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return lessNum[0];
        }
        string res("");
        for (int val = 1000000000, pos = 0; val > 0; val /= 1000, ++pos) {
            int tmp = num / val;
            if (tmp > 0) {
                if (pos == 3) {
                    res += Convert(tmp);
                } else {
                    res += Convert(tmp) + " " + splitNum[pos] + " ";
                }  
            }
            num = num % val;
        }
        res.erase(res.find_last_not_of(" ") + 1);
        return res;
    }

    string Convert(int num)
    {
        string res("");
        int left = num / 100;
        if (left > 0) {
            res += lessNum[left] + " Hundred ";
        }

        int right = (num % 100);
        if (right >= 20) {
            res += greaterNum[right / 10 - 2];
            if (right % 10 > 0) {
                res += " " + lessNum[right % 10];
            }
        } else {
            if (right > 0) {
                res += lessNum[right];
            }
        }
        res.erase(res.find_last_not_of(" ") + 1);
        return res;
    }

private:
    const vector<string> lessNum = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> greaterNum = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"};
    const vector<string> splitNum = {"Billion", "Million", "Thousand", " "};
};
// @lc code=end

