class Solution {

    unordered_set<string> ss;
    int res = 0;
    int n;

    void dfs(int idx, string& s) {
        if (idx == n) {
            res = max(res, static_cast<int>(ss.size()));
            return;
        }
        for (int len = 1;(idx + len - 1) < n;++len) {
            string str = s.substr(idx, len);
            if (ss.count(str))
                continue;
            ss.emplace(str);
            dfs(idx + len, s);
            ss.erase(str);
        }
    }
public:
    int maxUniqueSplit(string s) {
        n = static_cast<int>(s.size());
        dfs(0, s);
        return res;
    }
};