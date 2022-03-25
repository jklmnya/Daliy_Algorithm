class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size()), m = static_cast<int>(matrix[0].size());
        int rx1, rx2, ry1, ry2;
        int ans = INT_MIN;
        int dp[m], f[m];
        for (int x1 = 0;x1<n;++x1) {
            memset(f, 0, sizeof f);
            for (int x2 = x1;x2<n;++x2) {
                for (int i = 0;i<m;++i)
                    f[i] += matrix[x2][i];
                int res = f[0], y1 = 0, y2 = 0;
                if (res > ans) {
                    ans = res;
                    rx1 = x1, rx2 = x2, ry1 = y1, ry2 = y2;
                }
                dp[0] = f[0];
                for (int i = 1;i<m;++i) {
                    if (f[i] > f[i] + dp[i - 1]) {
                        res = f[i];
                        dp[i] = f[i];
                        y1 = y2 = i;
                    } else {
                        res = f[i] + dp[i - 1];
                        dp[i] = f[i] + dp[i - 1];
                        y2 = i;
                    }
                    if (res > ans) {
                        ans = res;
                        rx1 = x1, rx2 = x2, ry1 = y1, ry2 = y2;
                    }
                }
            }
        }
        return { rx1, ry1, rx2, ry2 };
    }
};