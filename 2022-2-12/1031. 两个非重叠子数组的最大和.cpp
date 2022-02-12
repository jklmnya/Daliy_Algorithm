class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = static_cast<int>(nums.size());
        for (int i = 1;i<n;++i)
            nums[i] += nums[i - 1];
        int res = 0;
        for (int s2 = 0, e2, k1 = 0;(e2 = s2 + firstLen - 1)<n;++s2) {
            int k2;
            if (s2 == 0)
                k2 = nums[e2];
            else
                k2 = nums[e2] - nums[s2 - 1];
            if (s2 - secondLen >= 0) {
                if (s2 - secondLen == 0)
                    k1 = nums[s2 - 1];
                else
                    k1 = max(k1, nums[s2 - 1] - nums[s2 - secondLen - 1]);
            }
            int k3 = 0;
            for (int s1 = e2 + 1, e1;(e1 = s1 + secondLen - 1)<n;++s1) {
                k3 = max(k3, nums[e1] - nums[s1 - 1]);
            }
            res = max(res, k2 + max(k1, k3));
        }
        return res;
    }
};