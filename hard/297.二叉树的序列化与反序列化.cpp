/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (root == nullptr) {
//             return "";
//         }
//         return to_string(root->val) + "(" + serialize(root->left) + "," +
//             serialize(root->right) + ")";
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         cout << data << endl;
//         TreeNode *root = nullptr;
//         string val{""};
//         stack<TreeNode *> st;

//         for (int pos = 0; pos < data.size(); ++pos) {
//             if (((data[pos] >= '0') && (data[pos] <= '9')) || data[pos] == '-') {
//                 val += data[pos];
//                 continue;
//             }

//             if (data[pos] == '(' || ((data[pos] == ',') && data[pos - 1] != ')')) {
//                 TreeNode *tmp = nullptr;
//                 if (val != "") {
//                     tmp = new TreeNode(stol(val));
//                     if (root == nullptr) {
//                         root = tmp;
//                     }
//                 }
//                 st.push(tmp);
//             } else if ((data[pos] == ')') && (data[pos - 1] != ')')) {
//                 TreeNode *left = st.top();
//                 st.pop();
//                 TreeNode *right = nullptr;
//                 if (val != "") {
//                     right = new TreeNode(stol(val));
//                 }
//                 st.top()->left = left;
//                 st.top()->right = right;
//             } else if ((data[pos] == ')') && (data[pos - 1] == ')')) {
//                 TreeNode *right = st.top();
//                 st.pop();
//                 TreeNode *left = st.top();
//                 st.pop();
//                 st.top()->left = left;
//                 st.top()->right = right;
//             }
//             val.clear();
//         }
//         return root;
//     }
// };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        return to_string(root->val) + "(" + serialize(root->left) + "," +
            serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        string val{""};
        stack<TreeNode *> st;

        for (int pos = 0; pos < data.size(); ++pos) {
            if (((data[pos] >= '0') && (data[pos] <= '9')) || data[pos] == '-') {
                val += data[pos];
                continue;
            }

            if (data[pos - 1] != ')') {
                TreeNode *tmp = nullptr;
                if (val != "") {
                    tmp = new TreeNode(stol(val));
                }
                st.push(tmp);
            }
            
            if ((data[pos] == ',') || (data[pos] == ')')) {
                TreeNode *tmp = st.top();
                st.pop();
                if (data[pos] == ',') {
                    st.top()->left = tmp;
                } else {
                    st.top()->right = tmp;
                }
            }
            val.clear();
        }
        return st.empty() ? nullptr : st.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

