class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> vv;
        for (int num : nums)
            ++vv[num];
        for (auto& [num, cnt] : vv) {
            if (num << 1 == k) {
                if (cnt >= 2) {
                    res += cnt / 2;
                    cnt -= (cnt / 2) << 1;
                }
            } else {
                if (vv.count(k - num) && vv[k - num]) {
                    int f = min(cnt, vv[k - num]);
                    res += f;
                    cnt -= f;
                    vv[k - num] -= f;
                }
            }
        }
        return res;
    }
};