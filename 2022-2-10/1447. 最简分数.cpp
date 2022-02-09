class Solution {

    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }

public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = n;i>=2;--i) {
            for (int j = i - 1;j>=1;--j) {
                if (gcd(i, j) == 1) {
                    string ans = to_string(j) + '/' + to_string(i);
                    res.push_back(move(ans));
                }
            }
        }
        return res;
    }
};