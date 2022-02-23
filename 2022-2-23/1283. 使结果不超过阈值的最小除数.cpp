class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6 + 10;
        while (left <= right) {
            int mid = (left + right) >> 1;
            long long cnt = 0ll;
            for (int num : nums) {
                if (num % mid)
                    cnt += (num / mid) + 1;
                else
                    cnt += num / mid;
            }   
            if (cnt > threshold)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};