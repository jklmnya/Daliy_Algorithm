class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = static_cast<int>(s.size());
        if (n < k)
            return false;
        int f[26];
        memset(f, 0, sizeof f);
        for (char ch : s)
            ++f[ch - 'a'];
        int s1 = 0;
        for (int num : f) {
            if (num % 2)
                ++s1;
        }
        return s1 <= k;
    }
};