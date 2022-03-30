class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        int lSum = accumulate(rolls.begin(), rolls.end(), 0);
        int rSum = sum - lSum;
        if (rSum < n || rSum > 6 * n)
            return {};
        int avg = rSum / n;
        int remain = rSum - avg * n;
        vector<int> res(n, avg);
        for (int i = 0;i<remain;++i)
            ++res[i];
        return res;
    }
};