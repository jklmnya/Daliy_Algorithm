class Solution {
public:
    bool hasAlternatingBits(int n) {
        int f1 = n & 1;
        n >>= 1;
        while (n) {
            int f2 = n & 1;
            if (f1 == f2)
                return false;
            f1 = f2;
            n >>= 1;
        }
        return true;
    }
};