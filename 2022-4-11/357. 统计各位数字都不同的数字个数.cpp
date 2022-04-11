class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        for (int i = 1;i<=n;++i) {
            int ans = 9, f = 9;
            for (int j = 1;j<i;++j) {
                ans *= f;
                --f;
            }
            res += ans;
        }
        return res;
    }
};