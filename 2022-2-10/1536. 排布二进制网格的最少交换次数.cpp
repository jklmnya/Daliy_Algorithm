class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int res = 0, n = static_cast<int>(grid.size());
        int f[n];
        memset(f, 0, sizeof f);
        for (int i = 0;i<n;++i) {
            int j = n - 1;
            while (j >= 0 && !grid[i][j])
                --j;
            f[i] = n - 1 - j;
        }
        for (int i = 0, need = n - 1;i<n-1;++i, --need) {
            if (f[i] >= need)
                continue;
            bool ff = false;
            for (int j = i + 1;j<n;++j) {
                if (f[j] >= need) {
                    res += j - i;
                    ff = true;
                    for (int k = j - 1;k>=i;--k)
                        swap(f[k + 1], f[k]);
                    break;
                }
            }
            if (!ff)
                return -1;
        }
        return res;
    }
};