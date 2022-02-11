class Solution {
public
    int minimumDifference(vectorint& nums, int k) {
        int n = static_castint(nums.size());
        if (n == 1)
            return 0;
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int l = 0, r;(r = l + k - 1)n;++l)
            res = min(res, nums[r] - nums[l]);
        return res;
    }
};