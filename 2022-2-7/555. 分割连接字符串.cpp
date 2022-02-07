class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string res = "", ss = "";
        for (auto& a : strs) {
            int s = 0, e = static_cast<int>(a.size()) - 1;
            while (s < e) {
                if (a[s] < a[e]) {
                    reverse(a.begin(), a.end());
                    break;
                } else if (a[s] > a[e]) {
                    break;
                } else {
                    ++s, --e;
                }
            }
            ss += a;
        }
        int s = 0, n = static_cast<int>(ss.size());
        for (auto& str : strs) {
            string ans = "";
            int cnt, s1;

            // cout << s << ' ' << s + static_cast<int>(str.size()) << '\n';

            for (int i = s;i<s + static_cast<int>(str.size());++i) {
                s1 = i, cnt = n;
                while (cnt--) {
                    ans += ss[s1 % n];
                    ++s1;
                }
                res = max(res, ans);
                ans.resize(0);
            }
            reverse(ss.begin() + s, ss.begin() + s + static_cast<int>(str.size()));
            for (int i = s;i<s + static_cast<int>(str.size());++i) {
                s1 = i, cnt = n;
                while (cnt--) {
                    ans += ss[s1 % n];
                    ++s1;
                }
                res = max(res, ans);
                ans.resize(0);
            }
            reverse(ss.begin() + s, ss.begin() + s + static_cast<int>(str.size()));
            s += static_cast<int>(str.size());
        }
        return res;
    }
};