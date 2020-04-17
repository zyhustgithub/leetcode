/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         TreeNode *pre = nullptr;
//         TreeNode *post = nullptr;
//         TreeNode *cur = nullptr;
//         bool isFinish = false;
//         DFS(root, cur, pre, post, isFinish);
//         if (post == nullptr) {
//             return;
//         }
//         post->val ^= pre->val;
//         pre->val ^= post->val;
//         post->val ^= pre->val;
//     }

//     void DFS(TreeNode *p, TreeNode *&cur, TreeNode *&pre, TreeNode *&post, bool &isFinish)
//     {
//         if ((p == nullptr) || isFinish) {
//             return;
//         }
        
//         if (p->left) {
//             DFS(p->left, cur, pre, post, isFinish);
//         }
//         if (cur != nullptr) {
//             if (cur->val > p->val) {
//                 if (pre == nullptr) {
//                     pre = cur;
//                 }
//                 if (post != nullptr) {
//                     isFinish = true;
//                     post = p;
//                     return;
//                 }
//                 post = p;
//             }
//         }
//         cur = p;
        
//         if (p->right) {
//             DFS(p->right, cur, pre, post, isFinish);
//         }
//     }
// };

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr;
        TreeNode *pos1 = nullptr;
        TreeNode *pos2 = nullptr;
        TreeNode *cur = root;
        TreeNode *last = nullptr;

        while (cur != nullptr) {
            if (cur->left != nullptr) {
                last = cur->left;
                while ((last->right != nullptr) && (last->right != cur)) {
                    last = last->right;
                }

                if (last->right == nullptr) {
                    last->right = cur;
                    cur = cur->left;
                } else {
                    if ((pre != nullptr) && (pre->val > cur->val)) {
                        if (pos1 == nullptr) {
                            pos1 = pre;
                        }
                        pos2 = cur;
                    }
                    pre = cur;
                    cur = cur->right;
                    last->right = nullptr;
                }
            } else {
                if ((pre != nullptr) && (pre->val > cur->val)) {
                    if (pos1 == nullptr) {
                        pos1 = pre;
                    }
                    pos2 = cur;
                }
                pre = cur;
                cur = cur->right;
            }
        }

        pos1->val ^= pos2->val;
        pos2->val ^= pos1->val;
        pos1->val ^= pos2->val;
    }
};
// @lc code=end

