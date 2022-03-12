class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = static_cast<int>(queries.size()), m = static_cast<int>(s.size());
        vector<int> res(n);
        vector<int> f(m + 1);
        vector<int> vv;
        for (int i = 1;i<=m;++i) {
            if (s[i - 1] == '*') {
                f[i] = f[i - 1] + 1;
            } else {
                f[i] = f[i - 1];
                vv.push_back(i);
            }
        }
        vv.push_back(INT_MAX);
        int i = 0;
        for (auto& q : queries) {
            int left = q[0] + 1, right = q[1] + 1;
            auto lIter = lower_bound(vv.begin(), vv.end(), left);
            auto rIter = lower_bound(vv.begin(), vv.end(), right);

            if (*lIter >= *rIter) {
                res[i++] = 0;
            } else {
                if (rIter != vv.begin() && *rIter > right)
                    --rIter;
                if (*lIter >= *rIter)
                    res[i++] = 0;
                else
                    res[i++] = f[*rIter] - f[*lIter - 1];
            }
        }
        return res;
    }
};