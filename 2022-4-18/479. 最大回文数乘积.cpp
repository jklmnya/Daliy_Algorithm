class Solution {

    static constexpr int MOD = 1337;

public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        int upper = pow(10, n) - 1;
        for (int left = upper;;--left) {
            long long num = left;
            for (int x = left;x>0;x/=10)
                num = num * 10 + x % 10;
            for (long long x = upper;x * x >= num;--x) {
                if (num % x == 0)
                    return num % MOD;
            }
        }
    }
};