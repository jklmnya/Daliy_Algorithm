class Solution {

public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> vv;
        for (int a : arr)
            ++vv[a];
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [k, v] : vv)
            pq.emplace(v);
        while (k > 0 && pq.size()) {
            int cnt = pq.top();
            pq.pop();
            if (cnt > k) {
                k = 0;
                pq.emplace(cnt - k);
            } 
            k -= cnt;
        }
        return static_cast<int>(pq.size());
    }
};