/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void dfs(Node* node, vector<int>& f) {
        if (node) {
            if (node->val >= 'a' && node->val <= 'z') {
                ++f[node->val - 'a'];
            } else {
                dfs(node->left, f);
                dfs(node->right, f);
            }
        }
    }

public:
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int> f1(26), f2(26);
        dfs(root1, f1);
        dfs(root2, f2);
        for (int i = 0;i<26;++i) {
            if (f1[i] != f2[i])
                return false;
        }
        return true;
    }
};