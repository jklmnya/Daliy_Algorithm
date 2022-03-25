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

    long long lastVal = LLONG_MIN;

public:
    bool isValidBST(TreeNode* root) {
        if (root) {
            if (!isValidBST(root->left))
                return false;
            if (lastVal >= root->val)
                return false;
            lastVal = root->val;
            if (!isValidBST(root->right))
                return false;
            return true;
        }
        return true;
    }
};