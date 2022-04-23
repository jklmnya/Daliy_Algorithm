class Solution {
public:
    vector<int> shortestToChar(string ss, char c) {
        int n = static_cast<int>(ss.size()); 
        vector<int> res(n);
        int s = 0;
        while (s < n && ss[s] != c)
            ++s;
        for (int i = s - 1;i>=0;--i)
            res[i] = s - i;
        int e = n - 1;
        while (s < n && ss[e] != c)
            --e;
        for (int i = e + 1;i<n;++i)
            res[i] = i - e;
        if (s == e)
            return res;
        while (s <= e) {
            int k = s + 1;
            while (k <= e && ss[k] != c)
                ++k;
            int len = k - s - 1;
            int mid = s + len / 2;
            for (int i = s + 1;i<=mid;++i)
                res[i] = i - s;
            for (int i = mid + 1;i<k;++i)
                res[i] = k - i;
            s = k;
        }
        return res;
    }
};