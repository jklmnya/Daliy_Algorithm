class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0, n = static_cast<int>(time.size());
        int cnt[60];
        memset(cnt, 0, sizeof cnt);
        for (int i = 1;i<n;++i) {
            ++cnt[time[i - 1] % 60];
            int x = time[i] % 60;
            if (x == 0)
                res += cnt[0];
            else
                res += cnt[60 - x];
        }
        return res;
    }
};