class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1, r = 100005;
        while (l <= r) {
            long long cnt = 0ll;
            int mid = (l + r) >> 1;
            for (auto& len : ribbons)
                cnt += len / mid;
            if (cnt >= k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l - 1;
    }
};