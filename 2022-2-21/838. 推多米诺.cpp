class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = static_cast<int>(dominoes.size());
        int s = 0, e = n - 1;
        while (s < n && dominoes[s] == '.')
            ++s;
        if (s < n) {
            if (dominoes[s] == 'L') {
                for (int i = 0;i<s;++i)
                    dominoes[i] = 'L';
            }
        }
        while (e >= 0 && dominoes[e] == '.')
            --e;
        if (e >= 0) {
            if (dominoes[e] == 'R') {
                for (int i = e;i<n;++i)
                    dominoes[i] = 'R';
            }
        }
        while (s < e) {
            int k = s + 1;
            while (k <= e && dominoes[k] == '.')
                ++k;
            if (k <= e) {
                if (dominoes[s] == 'L') {
                    if (dominoes[k] == 'L') {
                        for (int i = s;i<=k;++i)
                            dominoes[i] = 'L';
                    }
                } else {
                    if (dominoes[k] == 'R') {
                        for (int i = s;i<=k;++i)
                            dominoes[i] = 'R';
                    } else {
                        int len = (k - s + 1) / 2;
                        for (int i = 0;i<len;++i) {
                            dominoes[s + i] = 'R';
                            dominoes[k - i] = 'L';
                        }
                    }
                }
            }
            s = k;
        }
        return dominoes;
    }
};