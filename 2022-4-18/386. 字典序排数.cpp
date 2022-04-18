class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);
        int now = 1;
        for (int i = 0;i<n;++i) {
            res.push_back(now);
            if (now * 10 <= n) {
                now *= 10;
            } else {
                while (now % 10 == 9 || now + 1 > n)
                    now /= 10;
                now++;
            }
        }
        return res;
    }
};