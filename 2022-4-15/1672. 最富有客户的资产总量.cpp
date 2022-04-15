class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (int i = 0;i<accounts.size();++i) {
            int f = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            if (f > res)
                res = f;
        }
        return res;
    }
};