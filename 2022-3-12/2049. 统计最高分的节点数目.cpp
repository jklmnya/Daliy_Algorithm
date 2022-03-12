class Solution {

    vector<int> f;
    vector<vector<int>> g;

    int dfs(int node) {
        if (!g[node].size())
            return f[node];
        for (int next : g[node])
            f[node] += dfs(next);
        return f[node];
    }

public:
    int countHighestScoreNodes(vector<int>& parents) {
        int res = 0;
        long long cnt = 0;
        int n = static_cast<int>(parents.size());
        f.resize(n, 1);
        g.resize(n);
        for (int i = 0;i<n;++i) {
            if (parents[i] != -1)
                g[parents[i]].push_back(i);
        }
        dfs(0);
        for (int i = 0;i<n;++i) {
            long long now = 1;
            long long m1 = n - f[i];
            if (m1 > 0)
                now *= m1;
            for (int next : g[i])
                now *= f[next];
            if (now > cnt) {
                cnt = now;
                res = 1;
            } else if (now == cnt) {
                ++res;
            } else {

            }
        }
        return res;
    }
};