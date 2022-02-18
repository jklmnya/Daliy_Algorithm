class Solution {

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int temp[r - l + 1];
        int s1 = l, s2 = mid + 1, s3 = 0;
        while (s1 <= mid && s2 <= r) {
            if (nums[s1] < nums[s2]) {
                temp[s3++] = nums[s1];
                ++s1;
            } else {
                temp[s3++] = nums[s2];
                ++s2;
            }
        }
        while (s1 <= mid)
            temp[s3++] = nums[s1++];
        while (s2 <= r)
            temp[s3++] = nums[s2++];
        s3 = 0;
        while (l <= r)
            nums[l++] = temp[s3++];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);
        return nums;
    }
};