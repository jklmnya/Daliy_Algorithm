class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int s = 0, e = static_cast<int>(nums.size()) - 1;
        while (s < e) {
            while (s < e && nums[s] % 2 == 0)
                ++s;
            while (e > s && nums[e] % 2)
                --e;
            if (s < e) {
                swap(nums[s], nums[e]);
                ++s;
                --e;
            }
        }
        return nums;
    }
};