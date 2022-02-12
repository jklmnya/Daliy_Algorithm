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

    TreeNode* res = nullptr;

    void dfs(TreeNode* node, TreeNode* target) {
        if (node) {
            if (node->val == target->val) {
                res = node;
                return;
            }
            dfs(node->left, target);
            if (!res)
                dfs(node->right, target);
        }
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target);
        return res;
    }
};