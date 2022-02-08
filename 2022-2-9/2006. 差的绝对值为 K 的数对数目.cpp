class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int f[105];
        memset(f, 0, sizeof f);
        for (int num : nums)
            ++f[num];
        int res = 0;
        for (int i = 1;i<=100;++i) {
            if (f[i]) {
                if (i + k <= 100 && f[i + k])
                    res += f[i] * f[i + k];
                if (i - k >= 1 && f[i - k])
                    res += f[i] * f[i - k];
            }
        }
        return res >> 1;
    }
};