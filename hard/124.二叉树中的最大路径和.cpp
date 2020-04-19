/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int val = -0x3f3f3f;
        MaxNumTree(root, val);
        return val;
    }

    int MaxNumTree(TreeNode *curNode, int &val)
    {
        if (curNode == nullptr) {
            return 0;
        }

        int left = MaxNumTree(curNode->left, val);
        int right = MaxNumTree(curNode->right, val);
        int ltr = curNode->val + max(0, left) + max(0, right);
        val = (val < ltr) ? ltr : val;
        return curNode->val + max(0, max(left, right));
    }
};
// @lc code=end

