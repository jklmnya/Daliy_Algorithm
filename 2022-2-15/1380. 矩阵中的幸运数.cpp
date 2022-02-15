class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size()), m = static_cast<int>(matrix[0].size());
        int minV[n], maxV[m];
        for (int i = 0;i<n;++i)
            minV[i] = *min_element(matrix[i].begin(), matrix[i].end());
        for (int i = 0;i<m;++i) {
            int ans = 0;
            for (int j = 0;j<n;++j)
                ans = max(ans, matrix[j][i]);
            maxV[i] = ans;
        }
        vector<int> res;
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<m;++j) {
                if (matrix[i][j] == minV[i] && matrix[i][j] == maxV[j])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};