class Solution {
    
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0;i<=30;++i) {
            int bit_c = (c >> i) & 1;
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            if ((bit_a | bit_b) != bit_c) {
                if (bit_c) {
                    ++res;
                } else {
                    res += bit_a ? 1 : 0;
                    res += bit_b ? 1 : 0;
                }
            }
        }
        return res;
    }
};