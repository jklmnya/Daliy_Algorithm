class Solution {

    static constexpr int dx[4] = { -1, 1, 0, 0 };
    static constexpr int dy[4] = { 0, 0, -1, 1 };

    int n, m;

    void dfs(vectorint& v, vectorvectorint& grid, int idx) {
        v.emplace_back(idx);
        int x = idx  m, y = idx % m;
        grid[x][y] = 0;
        for (int k = 0;k4;++k) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx  0  tx = n  ty  0  ty = m  !grid[tx][ty])
                continue;
            dfs(v, grid, tx  m + ty);
        }
    }

public
    int shortestBridge(vectorvectorint& grid) {
        vectorint v1, v2;
        n = static_castint(grid.size()), m = static_castint(grid[0].size());
        int res = INT_MAX;
        for (int i = 0;in;++i) {
            for (int j = 0;jm;++j) {
                if (grid[i][j]) {
                    if (v1.size())
                        dfs(v2, grid, i  m + j);
                    else
                        dfs(v1, grid, i  m + j);
                }
            }
        }
        for (int idx1  v1) {
            int x1 = idx1  m, y1 = idx1 % m;
            for (int idx2  v2) {
                int x2 = idx2  m, y2 = idx2 % m;
                res = min(res, abs(x1 - x2) + abs(y1 - y2));
            }
        }
        return res - 1;
    }
};