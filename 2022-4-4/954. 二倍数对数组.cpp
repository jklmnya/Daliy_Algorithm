class Solution {

public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        unordered_map<int, int> vv;
        for (int a : arr)
            ++vv[a];
        if (vv.count(0) && vv[0] % 2)
            return false;
        sort(arr.begin(), arr.end());
        for (int i = 0;i<n;++i) {
            if (arr[i] > 0) {
                reverse(arr.begin() + i, arr.end());
                break;
            }
        }
        for (int x : arr) {
            if (x % 2 == 0 && vv[x]) {
                // cout << x << '\n';
                if (vv.count(x / 2) && vv[x] <= vv[x / 2]) {
                    vv[x / 2] -= vv[x];
                    vv[x] = 0;
                } else {
                    return false;
                }
            }    
        }
        for (auto& [k, v] : vv) {
            if (v)
                return false;
        }
        return true;
    }
};