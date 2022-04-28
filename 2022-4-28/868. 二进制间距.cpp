class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        vector<int> vv;
        for (int i = 0;i<=30;++i) {
            if ((n >> i) & 1)
                vv.emplace_back(i);
        }
        for (int i = 0;i<vv.size() - 1;++i)
            res = max(res, vv[i + 1] - vv[i]);
        return res;
    }
};