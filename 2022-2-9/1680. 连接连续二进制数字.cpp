class Solution {

    static constexpr int MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n) {
        long long res = 1ll;
        for (int i = 2;i<=n;++i) {
            int j = 30;
            while (j >= 0 && !((i >> j) & 1))
                --j;
            res = (res << (j + 1)) % MOD;
            res = (res + i) % MOD;
        }
        return res % MOD;
    }
};