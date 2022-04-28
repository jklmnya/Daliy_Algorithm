class Solution {

    vector<int> _nums;

public:
    Solution(vector<int>& nums) {
        _nums = std::move(nums);
    }

    
    int pick(int target) {
        int cnt = 0;
        int res;
        for (int i = 0;i<_nums.size();++i) {
            if (_nums[i] == target) {
                ++cnt;
                int r = rand() % cnt;
                if (r == 0)
                    res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */