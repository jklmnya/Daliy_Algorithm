class Solution {

    typedef long long LL;

public:
    LL subArrayRanges(vector<int>& nums) {
        LL res = 0ll;
        int n = static_cast<int>(nums.size());
        int leftMax[n], rightMax[n], leftMin[n], rightMin[n];
        
        stack<pair<int, int>> str;
        stack<pair<int, int>> stl;

        str.emplace(INT_MAX, n);
        stl.emplace(INT_MAX, -1);
        for (int i = n - 1;i>=0;--i) {
            while (str.size() && str.top().first <= nums[i])
                str.pop();
            rightMax[i] = str.top().second;
            str.emplace(nums[i], i);
        }
        for (int i = 0;i<n;++i) {
            while (stl.size() && stl.top().first < nums[i])
                stl.pop();
            leftMax[i] = stl.top().second;
            stl.emplace(nums[i], i);
        }

        while (str.size())
            str.pop();
        while (stl.size())
            stl.pop();

        str.emplace(INT_MIN, n);
        stl.emplace(INT_MIN, -1);
        for (int i = n - 1;i>=0;--i) {
            while (str.size() && str.top().first >= nums[i])
                str.pop();
            leftMin[i] = str.top().second;
            str.emplace(nums[i], i);
        }
        for (int i = 0;i<n;++i) {
            while (stl.size() && stl.top().first > nums[i])
                stl.pop();
            rightMin[i] = stl.top().second;
            stl.emplace(nums[i], i);
        }

        for (int i = 0;i<n;++i) {
            res += (LL)(nums[i]) * (i - leftMax[i]) * (rightMax[i] - i);
            res -= (LL)(nums[i]) * (i - leftMin[i]) * (rightMin[i] - i);
        }
        return res;
    }
};