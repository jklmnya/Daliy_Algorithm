class Solution {

    static constexpr int MOD = 1e9 + 7;

    typedef long long LL;

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        LL res = 0ll;
        int right[n];
        memset(right, 0, sizeof right);
        stack<pair<int, int>> st;
        st.emplace(INT_MIN, n);
        for (int i = n - 1;i>=0;--i) {
            while (st.size() && arr[i] <= st.top().first)
                st.pop();
            right[i] = st.top().second;
            st.emplace(arr[i], i);
        }
        while (st.size())
            st.pop();
        st.emplace(INT_MIN, -1);
        for (int i = 0;i<n;++i) {
            while (st.size() && arr[i] < st.top().first)
                st.pop();
            int leftCnt = i - st.top().second;
            int rightCnt = right[i] - i;
            res = (res + (LL)(leftCnt * rightCnt) * arr[i]) % MOD;
            st.emplace(arr[i], i);  
        }
        return static_cast<int>(res);
    }
};