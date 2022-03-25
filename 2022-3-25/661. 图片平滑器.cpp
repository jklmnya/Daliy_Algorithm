class Solution {

    static constexpr int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    static constexpr int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = static_cast<int>(img.size()), m = static_cast<int>(img[0].size());
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<m;++j) {
                int x = img[i][j], y = 1;
                for (int k = 0;k<8;++k) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                        continue;
                    ++y;
                    x += img[tx][ty];
                }
                res[i][j] = x / y;
            }
        }
        return res;
    }
};