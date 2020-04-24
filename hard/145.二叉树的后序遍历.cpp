/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
/* 后序遍历 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        stack<TreeNode *> st;
        st.push(root);
        vector<int> res;

        while(!st.empty()) {
            TreeNode *tmp = st.top();
            if (tmp == nullptr) {
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
                continue;
            }

            st.push(nullptr);

            if (tmp->right != nullptr) {
                st.push(tmp->right);
            }

            if (tmp->left != nullptr) {
                st.push(tmp->left);
            }
        }

        return res;
    }
};

/* 先序遍历 */
// class Solution {
// public:
//     vector<int> PreOrderTraversal(TreeNode* root) {
//         if (root == nullptr) {
//             return {};
//         }
//         stack<TreeNode *> st;
//         TreeNode *curNode = root;
//         vector<int> res;

//         while (!st.empty() || curNode) {
//             while (curNode != nullptr) {
//                 res.push_back(curNode->val);
//                 st.push(curNode);
//                 curNode = curNode->left;
//             }

//             while (!st.empty()) {
//                 curNode = st.top()->right;
//                 st.pop();
//                 if (curNode != nullptr) {
//                     break;
//                 }
//             }
//         }

//         return res;
//     }
// };

/* 先序遍历精华版 */
// class Solution {
// public:
//     vector<int> PreOrderTraversal(TreeNode* root) {
//         if (root == nullptr) {
//             return {};
//         }
//         stack<TreeNode *> st;
//         st.push(root);
//         vector<int> res;

//         while (!st.empty()) {
//             TreeNode *tmp = st.top();
//             st.pop();
//             res.push_back(tmp->val);

//             if (tmp->right != nullptr) {
//                 st.push(tmp->right);
//             }

//             if (tmp->left != nullptr) {
//                 st.push(tmp->left);
//             }
//         }

//         return res;
//     }
// };


/* 中序遍历 */
// class Solution {
// public:
//     vector<int> InOrderTraversal(TreeNode* root) {
//         if (root == nullptr) {
//             return {};
//         }
//         stack<TreeNode *> st;
//         st.push(root);
//         vector<int> res;

//         while(!st.empty()) {
//             TreeNode *tmp = st.top();
//             if (tmp == nullptr) {
//                 st.pop();
//                 TreeNode *next = st.top();
//                 res.push_back(next->val);
//                 st.pop();
//                 if (next->right != nullptr) {
//                     st.push(next->right);
//                 }
//                 continue;
//             }

//             st.push(nullptr);

//             if (tmp->left != nullptr) {
//                 st.push(tmp->left);
//             }
//         }

//         return res;
//     }
// };
// @lc code=end

