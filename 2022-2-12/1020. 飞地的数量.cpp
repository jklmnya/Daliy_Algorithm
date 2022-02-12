class Solution {

    static constexpr int dx[4] = { -1, 1, 0, 0 };
    static constexpr int dy[4] = { 0, 0, -1, 1 };

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
        queue<int> q;
        int res = 0;
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<m;++j) {
                if (grid[i][j] == 1) {
                    ++res;
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                        q.push(i * m + j); 
                }  
            }
        }
        while (q.size()) {
            int _hash = q.front();
            q.pop();
            int x = _hash / m, y = _hash % m;
            if (grid[x][y] == 0)
                continue;
            --res;
            grid[x][y] = 0;
            for (int i = 0;i<4;++i) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || !grid[tx][ty])
                    continue;
                q.emplace(tx * m + ty);
            }
        }
        return res;
    }
};