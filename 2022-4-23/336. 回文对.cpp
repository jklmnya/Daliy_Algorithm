typedef unsigned long long ULL;
const int P = 131;

ULL Hash[5005][305][2];
ULL Ps[305];

class Solution {

    ULL getHash(int idx, int left, int right, int f) {
        return Hash[idx][right][f] - Hash[idx][left - 1][f] * Ps[right - left + 1];
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = static_cast<int>(words.size());
        Ps[0] = 1ull;
        for (int i = 1;i<=300;++i)
            Ps[i] = Ps[i - 1] * P;
        for (int i = 0;i<n;++i) {
            int m = static_cast<int>(words[i].size());
            for (int j = 0;j<m;++j)
                Hash[i][j + 1][0] = Hash[i][j][0] * P + (words[i][j] - 'a' + 1);
            for (int j = m - 1;j>=0;--j)
                Hash[i][m - j][1] = Hash[i][m - j - 1][1] * P + (words[i][j] - 'a' + 1);
        }
        vector<vector<int>> res;
        for (int i = 0;i<n;++i) {
            for (int j = i + 1;j<n;++j) {
                int l1 = static_cast<int>(words[i].size()), l2 = static_cast<int>(words[j].size());
                if (l1 == l2) {
                    if (getHash(i, 1, l1, 0) == getHash(j, 1, l2, 1))
                        res.push_back(std::move(vector<int> {i, j} ));
                    if (getHash(i, 1, l1, 1) == getHash(j, 1, l2, 0))
                        res.push_back(std::move(vector<int> {j, i} ));
                } else {
                    int len = (l1 + l2) >> 1;
                    ULL h1, h2, h3, h4;
                    if (l1 >= len) {
                        h1 = getHash(i, 1, len, 0), h2 = getHash(i, 1, len, 1);
                        int k = min(len, l2);
                        h3 = getHash(j, 1, k, 1), h4 = getHash(j, 1, k, 0);
                        if (k < len) {
                            h3 = h3 * Ps[len - k] + getHash(i, 1, len - k, 1);
                            h4 = h4 * Ps[len - k] + getHash(i, 1, len - k, 0);
                        }
                    } else {
                        h2 = getHash(j, 1, len, 0), h1 = getHash(j, 1, len, 1);
                        int k = min(len, l1);
                        h4 = getHash(i, 1, k, 1), h3 = getHash(i, 1, k, 0);
                        if (k < len) {
                            h3 = h3 * Ps[len - k] + getHash(j, 1, len - k, 0);
                            h4 = h4 * Ps[len - k] + getHash(j, 1, len - k, 1);
                        }
                    }
                    if (h1 == h3)
                        res.push_back(std::move(vector<int> {i, j} ));
                    if (h2 == h4)
                        res.push_back(std::move(vector<int> {j, i} ));
                }
            }
        }
        return res;
    }
};