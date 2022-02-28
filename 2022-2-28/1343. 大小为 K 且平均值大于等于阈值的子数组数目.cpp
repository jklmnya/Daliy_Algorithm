class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0, s = 0, e = 0, n = static_cast<int>(arr.size());
        int now = 0;
        while (e < n) {
            now += arr[e];
            if (e - s + 1 >= k) {
                if (now / k >= threshold)
                    ++res;
                now -= arr[s];
                ++s;
            }
            ++e;
        }
        return res;
    }
};