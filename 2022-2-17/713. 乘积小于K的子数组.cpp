class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 1, res = 0;
        int s = 0, e = 0, n = static_cast<int>(nums.size());
        while (e < n) {
            cnt *= nums[e];
            while (cnt >= k && s <= e) {
                cnt /= nums[s];
                ++s;
            }
            res += e - s + 1;
            ++e;
        }
        return res;
    }
};