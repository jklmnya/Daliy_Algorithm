class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int right[n];
        int res = 0;
        for (int i = n - 1, cnt = 0;i>=0;--i) {
            right[i] = cnt;
            if (nums[i])
                ++cnt;
            else
                cnt = 0;
        }
        for (int i = 0, cnt = 0;i<n;++i) {
            res = max(res, cnt + right[i]);
            if (nums[i])
                ++cnt;
            else
                cnt = 0;
        }
        return res;
    }
};