/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int numSize1 = nums1.size();
        int numSize2 = nums2.size();

        vector<int> res;
        for (int len1 = max(0, k - numSize2); len1 <= min(k, numSize1);
            ++len1) {
            int len2 = k - len1;
            vector<int> num1 = GetMaxNum(nums1, len1);
            vector<int> num2 = GetMaxNum(nums2, len2); 
            vector<int> ans = MergeNum(num1, num2);
            if (res.empty() || (res < ans)) {
                res = ans;
            }
        }
        return res;
    }

    vector<int> MergeNum(vector<int> &nums1, vector<int> &nums2)
    {
        int left = 0;
        int right = 0;
        vector<int> res;
        while ((left < nums1.size()) && (right < nums2.size())) {
            if (lexicographical_compare(nums1.begin() + left, nums1.end(),
                nums2.begin() + right, nums2.end())) {
                res.push_back(nums2[right]);
                ++right;
            } else {
                res.push_back(nums1[left]);
                ++left;
            }
        }

        while (left < nums1.size()) {
            res.push_back(nums1[left]);
            ++left;
        }
        while (right < nums2.size()) {
            res.push_back(nums2[right]);
            ++right;
        }
        return res;
    }

    vector<int> GetMaxNum(vector<int> &nums, int len)
    {
        vector<int> res;
        if (len == 0) {
            return res;
        }
        int numSize = nums.size();
        int limit = numSize - len;

        for (int pos = 0; pos < numSize; ++pos) {
            while (!res.empty() && (nums[pos] > res.back()) &&
                (limit > 0)) {
                res.pop_back();
                --limit;
            }
            res.push_back(nums[pos]);
        }
        res.resize(len);
        return res;
    }
};
// @lc code=end

