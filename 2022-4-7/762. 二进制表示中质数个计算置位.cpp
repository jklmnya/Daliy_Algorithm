class Solution {

    bool f[32] = {
        false, false, true, true, false, true, 
    };

    int lowbit(int x) {
        return x & (-x);
    }

    int getOnes(int x) {
        int ans = 0;
        while (x) {
            ++ans;
            x -= lowbit(x);
        }
        return ans;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        while (left <= right) {
            if (f[getOnes(left)])
                ++res;  
            ++left;
        }
        return res;
    }
};