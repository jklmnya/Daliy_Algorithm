class Solution {

    static constexpr int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    static constexpr int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    static constexpr double d = (double)1 / 8;

public:
    double knightProbability(int n, int k, int row, int column) {
        double f[n][n][2];
        memset(f, 0, sizeof f);
        f[row][column][0] = 1;
        for (int i = 1;i<=k;++i) {
            for (int x = 0;x<n;++x) {
                for (int y = 0;y<n;++y) {
                    f[x][y][i % 2] = 0;
                    const int j = (i % 2) == 0 ? 1 : 0;
                    for (int m = 0;m<8;++m) {
                        int tx = x + dx[m], ty = y + dy[m];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= n)
                            continue;
                        f[x][y][i % 2] += f[tx][ty][j] * d;
                    }
                }
            }
        }
        double res = 0;
        for (int x = 0;x<n;++x) {
            for (int y = 0;y<n;++y)
                res += f[x][y][k % 2];
        }
        return res;
    }
};