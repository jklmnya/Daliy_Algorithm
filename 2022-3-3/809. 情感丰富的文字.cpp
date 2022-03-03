class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0, n = static_cast<int>(s.size());
        for (auto& word : words) {
            int m = static_cast<int>(word.size());
            int s1 = 0, s2 = 0;
            while (s1 < n && s2 < m) {
                if (s[s1] != word[s2])
                    break;
                int e1 = s1, e2 = s2;
                while (e1 < n && s[e1] == s[s1])
                    ++e1;
                while (e2 < m && word[e2] == word[s2])
                    ++e2;
                if ((e1 - s1 < 3 && e1 - s1 != e2 - s2) || e2 - s2 > e1 - s1)
                    break;
                s1 = e1;
                s2 = e2;
            }
            if (s1 == n && s2 == m)
                ++res;
        }
        return res;
    }
};