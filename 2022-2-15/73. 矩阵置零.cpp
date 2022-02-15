class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size()), m = static_cast<int>(matrix[0].size());
        bool f1[n], f2[m];
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<m;++j) {
                if (!matrix[i][j]) {
                    f1[i] = f2[j] = true;
                }
            }
        }
        for (int i = 0;i<n;++i) {
            if (f1[i]) {
                for (int j = 0;j<m;++j)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 0;i<m;++i) {
            if (f2[i]) {
                for (int j = 0;j<n;++j)
                    matrix[j][i] = 0;
            }
        }
    }
};