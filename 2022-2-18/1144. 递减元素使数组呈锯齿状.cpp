class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res = 0, ans = 0, n = static_cast<int>(nums.size());
        nums.push_back(INT_MAX);
        for (int i = 1;i<n;i+=2) {
            if (nums[i] >= nums[i + 1] || nums[i] >= nums[i - 1])
                res += nums[i] - min(nums[i + 1], nums[i - 1]) + 1;
        }
        nums[n] = INT_MIN;
        for (int i = 1;i<n;i+=2) {
            if (nums[i] <= nums[i + 1]) {
                ans += nums[i + 1] - nums[i] + 1;
                nums[i + 1] = nums[i] - 1;
            }
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i - 1] = nums[i] - 1;
            }
        }
        return min(res, ans);
    }
};