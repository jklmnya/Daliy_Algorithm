class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int n = static_cast<int>(nums.size());
        int minVal = nums[0];
        for (int i = 1;i<n;++i) {
            if (nums[i] > minVal) {
                res = max(res, nums[i] - minVal);
            } else {
                minVal = nums[i];
            }
        }
        return res;
    }
};