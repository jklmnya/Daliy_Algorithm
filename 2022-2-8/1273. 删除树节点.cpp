class Solution {

    vector<vector<int>> g;
    vector<bool> f;

    void dfs(int node) {
        if (f[node])
            return;
        f[node] = true;
        for (int next : g[node])
            dfs(next);
    }

public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int cnt[nodes];
        g.resize(nodes);
        f.resize(nodes);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0;i<nodes;++i) {
            if (parent[i] != -1) {
                ++cnt[parent[i]];
                g[parent[i]].emplace_back(i);
            }
        }
        queue<int> q;
        for (int i = 0;i<nodes;++i) {
            if (!cnt[i])
                q.emplace(i);
        }
        int ss = static_cast<int>(q.size());
        while (q.size()) {
            while (ss--) {
                int node = q.front();
                q.pop();
                if (parent[node] == -1)
                    continue;
                --cnt[parent[node]];
                value[parent[node]] += value[node];
                if (cnt[parent[node]] == 0)
                    q.emplace(parent[node]);
            }
            ss = static_cast<int>(q.size());
        }
        for (int i = 0;i<nodes;++i) {
            if (value[i] == 0)
                dfs(i);
        }
        int res = 0;
        for (bool b : f) {
            if (!b)
                ++res;
        }
        return res;
    }
};