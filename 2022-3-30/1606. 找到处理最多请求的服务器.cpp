class Solution {
 
    struct S {
        int id, time;
        S(int _id, int _time) : id(_id), time(_time) {}
        bool operator<(const S& s) const {
            return time > s.time;
        }
    };

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = static_cast<int>(arrival.size()), maxV = 0, now = 0;;
        vector<int> cnt(k);
        priority_queue<S> pq;
        set<int> ss;
        for (int i = 0;i<k;++i)
            ss.insert(i);
        for (int i = 0;i<n;++i) {
            while (pq.size() && pq.top().time <= arrival[i]) {
                ss.insert(pq.top().id);
                pq.pop();
            }
            if (!ss.size())
                continue;
            int idx = i % k;
            if (ss.count(idx)) {
                cnt[idx]++;
                ss.erase(idx);
                pq.emplace(idx, arrival[i] + load[i]);
            } else {
                auto iter = ss.upper_bound(idx);
                if (iter != ss.end()) {
                    cnt[*iter]++;
                    pq.emplace(*iter, arrival[i] + load[i]);
                    ss.erase(*iter);
                } else {
                    cnt[*ss.begin()]++;
                    pq.emplace(*ss.begin(), arrival[i] + load[i]);
                    ss.erase(*ss.begin());
                }
            }
        }
        for (int i = 0;i<k;++i) {
            if (cnt[i] > maxV) {
                maxV = cnt[i];
                now = 0;
                cnt[now] = i;
            } else if (cnt[i] == maxV) {
                cnt[++now] = i;
            }
        }
        cnt.resize(now + 1);
        return cnt;
    }
};