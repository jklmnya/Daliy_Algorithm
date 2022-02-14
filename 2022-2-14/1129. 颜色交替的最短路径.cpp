class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& r : redEdges) {
            int s = r[0], e = r[1];
            g[s].emplace_back(e, 0);
        }
        for (auto& b : blueEdges) {
            int s = b[0], e = b[1];
            g[s].emplace_back(e, 1);
        }
        vector<int> res(n, -1);
        queue<pair<int, int>> q;
        q.emplace(0, -1);
        int cnt = 0, ss = 1;
        bool st[2][n];
        memset(st, 0, sizeof st);
        while (q.size()) {
            while (ss--) {
                auto [node, color] = q.front();
                q.pop();
                if (color >= 0) {
                    if (st[color][node])
                        continue;
                    st[color][node] = true;
                }
                if (res[node] < 0)
                    res[node] = cnt;
                for (auto& [next, c] : g[node]) {
                    if (c != color)
                        q.emplace(next, c);
                }
            }
            ++cnt;
            ss = q.size();
        }
        return res;
    }
};