/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int numSize = nums.size();
        if (numSize < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int pre = 0;
        int post = 0;
        for (int a = 0; a < numSize - 3; ++a) {
            if ((a > 0) && (nums[a] == nums[a - 1])) {
                continue;
            }
            for (int b = a + 1; b < numSize - 2; ++b) {
                if ((b > a + 1) && nums[b] == nums[b - 1]) {
                    continue;
                }
                pre = b + 1;
                post = numSize - 1;
                while (pre < post) {
                    int tmp = nums[a] + nums[b] + nums[pre] + nums[post];
                    if (tmp < target) {
                        while ((nums[pre] == nums[++pre]) && (pre < post)) {}
                    } else if (tmp > target) {
                        while ((nums[post] == nums[--post]) && (pre < post)) {}
                    } else {
                        res.push_back(vector<int>({nums[a], nums[b], nums[pre], nums[post]}));
                        while ((nums[pre] == nums[++pre]) && (pre < post)) {}
                        while ((nums[post] == nums[--post]) && (pre < post)) {}
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

