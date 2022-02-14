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

int f[1005];

class Solution {

    int getMaxDepth(TreeNode* node) {
        if (!node)
            return 0;
        int depth = max(getMaxDepth(node->left), getMaxDepth(node->right)) + 1;
        f[node->val] = depth;
        return depth;
    }

    TreeNode* res = nullptr;

    void dfs(TreeNode* node) {
        if (!node)
            return;
        int leftDepth = node->left ? f[node->left->val] : 0;
        int rightDepth = node->right ? f[node->right->val] : 0;
        if (leftDepth > rightDepth) {
            dfs(node->left);
        } else if (leftDepth < rightDepth) {
            dfs(node->right);
        } else {
            res = node;
            return;
        }
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        getMaxDepth(root);
        dfs(root);
        return res;
    }
};