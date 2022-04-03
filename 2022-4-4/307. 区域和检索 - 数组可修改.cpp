class NumArray {

    int ss[30005];
    vector<int> vv;
    int n;

    inline int lowbit(int x) {
        return x & (-x);
    }

    void update_(int idx, int val) {
        while (idx <= n) {
            ss[idx] += val;
            idx += lowbit(idx);
        }
    }

    int getSum(int idx) {
        int res = 0;
        while (idx >= 1) {
            res += ss[idx];
            idx -= lowbit(idx);
        }
        return res;
    }

public:
    NumArray(vector<int>& nums) {
        memset(ss, 0, sizeof ss);
        n = static_cast<int>(nums.size());
        for (int i = 1;i<=n;++i)
            update_(i, nums[i - 1]);
        vv = move(nums);
    }
    
    void update(int index, int val) {
        int v = val - vv[index];
        vv[index] = val;
        update_(index + 1, v);
    }
    
    int sumRange(int left, int right) {
        return getSum(right + 1) - getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */