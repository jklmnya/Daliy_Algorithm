class Solution {

    inline bool check(char ch) {
        return isdigit(ch) || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '.' || ch == ' ';
    }

public:
    int lengthLongestPath(string input) {
        int res = 0;
        int s = 0, n = static_cast<int>(input.size());
        vector<pair<int, int>> vv;
        int t = 0;
        while (s < n) {
            int e = s;
            bool f = false;
            while (e < n && check(input[e])) {
                if (input[e] == '.')
                    f = true;
                ++e;
            }
            while (vv.size() && vv.back().first >= t) 
                    vv.pop_back();
            if (f) {
                int ans = e - s;
                for (int i = vv.size() - 1, j = 0;j<t;++j)
                    ans += vv[i - j].second;
                res = max(res, ans + t);
            } else {
                vv.emplace_back(t, e - s);
            }
            t = 0;
            while (++e < n && input[e] == '\t')
                ++t;
            s = e;
        }
        return res;
    }
};