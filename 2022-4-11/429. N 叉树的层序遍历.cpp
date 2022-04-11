/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<Node*> q;
        int ss = 1;
        vector<int> vv;
        q.push(root);
        while (q.size()) {
            vv.reserve(ss);
            vv.clear();
            while (ss--) {
                Node* node = q.front();
                q.pop();
                vv.push_back(node->val);
                for (auto next : node->children)
                    q.push(next);
            }
            res.push_back(vv);
            ss = q.size();
        }
        return res;
    }
};