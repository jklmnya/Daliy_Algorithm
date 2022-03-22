class Solution {

    vector<vector<int>> g;
    vector<int> dist;

    void bfs() {
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (q.size()) {
            int node = q.front();
            q.pop();
            for (int next : g[node]) {
                if (dist[next] == 0x3f3f3f3f) {
                    dist[next] = dist[node] + 1;
                    q.push(next);
                }
            }
        }
    }

public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = static_cast<int>(patience.size());
        g.resize(n);
        dist.resize(n, 0x3f3f3f3f);
        for (auto& edge : edges) {
            int s = edge[0], e = edge[1];
            g[s].push_back(e);
            g[e].push_back(s);
        }
        bfs();
        int res = 0;
        for (int i = 1;i<n;++i) {
            int d = dist[i] << 1;
            int t = ceil((double)(d) / patience[i]);
            res = max(res, (t - 1) * patience[i] + d);
        }
        return res + 1;
    }
};