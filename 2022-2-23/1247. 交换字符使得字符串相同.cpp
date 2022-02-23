class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = static_cast<int>(s1.size());
        int xy = 0, yx = 0;
        for (int i = 0;i<n;++i) {
            if (s1[i] == 'x' && s2[i] == 'y')
                ++xy;
            if (s1[i] == 'y' && s2[i] == 'x')
                ++yx;
        }
        if ((xy % 2 && yx % 2) || (xy % 2 == 0 && yx % 2 == 0)) {
            return xy / 2 + yx / 2 + (xy % 2) * 2;
        } else {
            return -1;
        }
    }
};