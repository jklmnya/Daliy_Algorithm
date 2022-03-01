class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        bool f[n];
        memset(f, 0, sizeof f);
        for (int i = 0;i<n;++i) {
            if (leftChild[i] >= 0)
                f[leftChild[i]] = true;
            if (rightChild[i] >= 0)
                f[rightChild[i]] = true;
        }
        int root = -1;
        for (int i = 0;i<n;++i) {
            if (!f[i]) {
                if (root < 0) {
                    root = i;
                } else {
                    return false;
                }
            }
        }
        if (root < 0)
            return false;
        memset(f, 0, sizeof f);
        queue<int> q;
        q.emplace(root);
        int ss = 1;
        while (q.size()) {
            while (ss--) {
                int node = q.front();
                q.pop();
                if (f[node])    
                    return false;
                f[node] = true;
                if (leftChild[node] >= 0)
                    q.emplace(leftChild[node]);
                if (rightChild[node] >= 0)
                    q.emplace(rightChild[node]);
            }
            ss = static_cast<int>(q.size());
        }
        for (bool st : f) {
            if (!st)
                return false;
        }
        return true;
    }
};