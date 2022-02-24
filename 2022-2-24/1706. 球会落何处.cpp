class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid[0].size());
        vector<int> res(m);
        for (int i = 0;i<m;++i) {
            int col = i;
            for (auto&& g : grid) {
                int dir = g[col];
                col += dir;
                if (col < 0 || col >= m || g[col] != dir) {
                    res[i] = -1;
                    break;
                }
            }
            if (res[i] != -1)
                res[i] = col;
        }
        return res;
    }
};