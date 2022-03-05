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

    bool check(TreeNode* A, TreeNode* B) {
        if (!B)
            return true;
        if (!A || A->val != B->val)
            return false;
        return check(A->left, B->left) && check(A->right, B->right) ;
    }

public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;
        return check(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};