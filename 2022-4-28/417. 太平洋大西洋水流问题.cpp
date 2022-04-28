class Solution {

    static constexpr int dx[4] = { -1, 1, 0, 0 };
    static constexpr int dy[4] = { 0, 0, -1, 1 };

    void fun(bool st[], int n, int m, vector<vector<int>>& h, bool f) {
        queue<pair<int, int>> q;
        if (f) {
            for (int i = 0;i<m;++i)
                q.emplace(0, i);
            for (int i = 1;i<n;++i)
                q.emplace(i, 0);
        } else {
            for (int i = 0;i<m;++i)
                q.emplace(n - 1, i);
            for (int i = 0;i<n - 1;++i)
                q.emplace(i, m - 1);
        }
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (st[x * m + y])
                continue;
            st[x * m + y] = true;
            for (int k = 0;k<4;++k) {
                int fx = x + dx[k], fy = y + dy[k];
                if (fx < 0 || fx >= n || fy < 0 || fy >= m || h[fx][fy] < h[x][y])
                    continue;
                q.emplace(fx, fy);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = static_cast<int>(heights.size()), m = static_cast<int>(heights[0].size());
        bool stP[n * m], stA[n * m];
        memset(stP, 0, sizeof stP);
        memset(stA, 0, sizeof stA);
        fun(stP, n, m, heights, true);
        fun(stA, n, m, heights, false);
        vector<vector<int>> res;
        for (int i = 0;i<n * m;++i) {
            if (stP[i] && stA[i])
                res.push_back(std::move( vector<int> {i / m, i % m}) );
        }
        return res;
    }
};