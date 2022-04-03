class Solution {

    bool check(int num) {
        int x = num;
        while (x) {
            int y = x % 10;
            if (!y || num % y)
                return false;
            x /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        while (left <= right) {
            if (check(left))
                res.push_back(left);
            ++left;
        }
        return res;
    }
};