class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = static_cast<int>(nums.size()) - 1;
        int s = 0, e = n;
        while (s < e) {
            int mid = (s + e) >> 1;
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if ((mid - s + 1) % 2)
                    e = mid - 2;
                else
                    s = mid + 1;
            } else if (mid < n && nums[mid] == nums[mid + 1]) {
                if ((e - mid + 1) % 2)
                    s = mid + 2;
                else
                    e = mid - 1;
            } else {
                return nums[mid];
            }
        }
        return nums[s];
    }
};