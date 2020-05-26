/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
constexpr int TARGET_NUM = 24;
constexpr double LIMIT = 1e-6;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> doubleNums(nums.begin(), nums.end());
        DFS(doubleNums);
        return flag;
    }

    void DFS(vector<double> &nums)
    {
        if (flag) {
            return;
        }
        if (nums.size() == 2) {
            flag = (IsValid(nums[0], nums[1])) ? true : false;
            return;
        }

        vector<double> nums_copy(nums.begin(), nums.end());
        for (int l = 0; l < nums_copy.size(); ++l) {
            double num1 = nums_copy[l];
            nums_copy.erase(nums_copy.begin() + l);
            vector<double> next_nums(nums_copy.begin(), nums_copy.end());
            for (int r = 0; r < next_nums.size(); ++r) {
                double num2 = next_nums[r];
                next_nums.erase(next_nums.begin() + r);

                next_nums.push_back(num1 + num2);
                DFS(next_nums);
                next_nums.pop_back();

                next_nums.push_back(num1 - num2);
                DFS(next_nums);
                next_nums.pop_back();

                next_nums.push_back(num2 - num1);
                DFS(next_nums);
                next_nums.pop_back();

                next_nums.push_back(num1 * num2);
                DFS(next_nums);
                next_nums.pop_back();

                next_nums.push_back(num1 / num2);
                DFS(next_nums);
                next_nums.pop_back();

                next_nums.push_back(num2 / num1);
                DFS(next_nums);
                next_nums.pop_back();

                next_nums.insert(next_nums.begin() + r, num2);
            }
            nums_copy.insert(nums_copy.begin() + l, num1);
        }
    }

    bool IsValid(double a, double b)
    {
        if (abs(a + b - TARGET_NUM) < LIMIT) {
            return true;
        }
        if ((abs(a - b - TARGET_NUM) < LIMIT) || (abs(b - a - TARGET_NUM) < LIMIT)) {
            return true;
        }
        if (abs(a * b - TARGET_NUM) < LIMIT) {
            return true;
        }
        if ((b != 0) && ((abs(a - b * TARGET_NUM) < LIMIT) || (abs(b - a * TARGET_NUM) < LIMIT))) {
            return true;
        }
        return false;
    }

private:
    bool flag = false;
};
// @lc code=end

