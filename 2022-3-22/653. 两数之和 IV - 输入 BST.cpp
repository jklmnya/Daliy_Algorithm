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

    unordered_map<int, int> ss;

    void dfs(TreeNode* node) {
        if (node) {
            ++ss[node->val];
            dfs(node->left);
            dfs(node->right);
        }
    }

public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        for (auto& [k1, v] : ss) {
            int k2 = k - k1;
            if (k1 == k2) {
                if (v > 1)
                    return 1;
            } else {
                if (ss.count(k2))
                    return 1;
            }
        }
        return 0;
    }
};