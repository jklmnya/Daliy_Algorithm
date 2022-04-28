class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
        for (int i = 0;i<n;++i) {
            int ans = 0;
            for (int j = 0;j<m;++j) {
                if (grid[i][j])
                    ++res;
                ans = max(ans, grid[i][j]);
            }
            res += ans;
        }
        for (int i = 0;i<m;++i) {
            int ans = 0;
            for (int j = 0;j<n;++j) {
                ans = max(ans, grid[j][i]);
            }
            res += ans;
        }
        return res;
    }
};