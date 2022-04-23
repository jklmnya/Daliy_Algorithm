class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = 0, now = 0;
        int n = static_cast<int> (nums.size());
        for (int i = 0;i<n;++i)
            res += i * nums[i];
        now = res;
        for (int i = n - 1;i>=1;--i) {
            int ans = now + sum - n * nums[i];
            res = max(res, ans);
            now = ans;
        }
        return res;
    }
};