/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    string res = "";
    void dfs(TreeNode* node) {
        if (node) {
            res += to_string(node->val);
            bool hasLeft = !(node->left == nullptr);
            bool hasRight = !(node->right == nullptr);
            if (hasLeft) {
                res += '(';
                dfs(node->left);
                res += ')';
                if (hasRight) {
                    res += '(';
                    dfs(node->right);
                    res += ')';
                }
            } else {
                if (hasRight) {
                    res += '(';
                    res += ')';
                    res += '(';
                    dfs(node->right);
                    res += ')';
                }
            }
        }
    }

public:
    string tree2str(TreeNode* root) {
        dfs(root);
        return res;
    }
};