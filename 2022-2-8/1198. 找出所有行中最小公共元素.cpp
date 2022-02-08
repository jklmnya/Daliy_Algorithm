class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = static_cast<int>(mat.size()), m = static_cast<int>(mat[0].size());
        if (n == 1)
            return mat[0][0];
        int f[n];
        memset(f, 0, sizeof f);
        for (int i = 0;i<m;++i) {
            int val = mat[0][i];
            bool fl = true;
            for (int j = 1;j<n;++j) {
                while (f[j] < m && mat[j][f[j]] < val)
                    ++f[j];
                if (f[j] >= m)
                    return -1;
                if (mat[j][f[j]] > val) {
                    fl = false;
                    break;
                }
            }
            if (fl)
                return val;
        }
        return -1;
    }
};