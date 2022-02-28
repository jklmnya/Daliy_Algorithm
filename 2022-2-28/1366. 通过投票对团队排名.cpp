class Solution {

    struct S {
        char team;
        vector<int> f;
        S(char _team, vector<int>&& _f) : team(_team), f(_f) {}
        bool operator<(const S& s) const {
            for (int i = 0;i<static_cast<int>(f.size());++i) {
                if (f[i] == s.f[i])
                    continue;
                return f[i] > s.f[i];
            }
            return team < s.team;
        }
    };

public:
    string rankTeams(vector<string>& votes) {
        int n = static_cast<int>(votes[0].size());
        vector<S> ans;
        ans.reserve(n);
        unordered_map<char, vector<int>> vv;
        for (auto& vote : votes) {
            for (int i = 0;i<n;++i) {
                if (!vv.count(vote[i])) {
                    vector<int> temp(n);
                    vv.emplace(vote[i], move(temp));
                }
                ++vv[vote[i]][i];
            }
        }
        for (auto& [k, v] : vv)
            ans.emplace_back(k, move(v));
        sort(ans.begin(), ans.end());
        string res;
        for (auto& [t, f] : ans)
            res += t;
        return res;
    }
};