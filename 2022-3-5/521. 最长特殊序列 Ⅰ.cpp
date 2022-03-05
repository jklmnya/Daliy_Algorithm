class Solution {
public:
    int findLUSlength(string a, string b) {
        int n = static_cast<int>(a.size()), m = static_cast<int>(b.size());
        if (n == m) {
            bool f = false;
            for (int i = 0;i<n;++i) {
                if (a[i] != b[i]) {
                    f = true;
                    break;
                }
            }
            return f ? n : -1;
        } else {
            return max(n, m);
        }
    }
};