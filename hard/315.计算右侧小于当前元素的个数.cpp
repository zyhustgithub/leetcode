/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
struct LineTree {
    int start;
    int end;
    int count;
    LineTree *left;
    LineTree *right;

    LineTree(int start, int end) : start(start), end(end), count(0),
        left(nullptr), right(nullptr) {} 
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int numSize = nums.size();
        if (numSize == 0) {
            return {};
        }
        vector<int> res(numSize, 0);
        int start = nums[0];
        int end = nums[0];
        for (auto n : nums) {
            if (n < start) {
                start = n;
            }
            if (n > end) {
                end = n;
            }
        }
        LineTree *root = InitLineTree(start, end);
        for (int pos = numSize - 1; pos >= 0; --pos) {
            if (nums[pos] == start) {
                res[pos] = 0;
            } else {
                res[pos] = GetCnt(root, nums[pos] - 1);
            }
            Update(root, nums[pos]);
        }

        return res;
    }

    LineTree *InitLineTree(int start, int end)
    {
        LineTree *root = new LineTree(start, end);
        if (start == end) {
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = InitLineTree(start, mid);
        root->right = InitLineTree(mid + 1, end);
        return root;
    }

    void Update(LineTree *root, int pos)
    {
        if ((root->start == pos) && (root->end == pos)) {
            ++root->count;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (mid < pos) {
            Update(root->right, pos);
        } else {
            Update(root->left, pos);
        }
        root->count = root->left->count + root->right->count;
    }

    int GetCnt(LineTree *root, int end)
    {
        if (root->end == end) {
            return root->count;
        }

        int leftNum = 0;
        int rightNum = 0;
        int mid = root->start + (root->end - root->start) / 2;

        if (mid < end) {
            leftNum = GetCnt(root->left, mid);
            rightNum = GetCnt(root->right, end);
        } else {
            leftNum = GetCnt(root->left, end);
        }
        return leftNum + rightNum;
    }
};
// @lc code=end

