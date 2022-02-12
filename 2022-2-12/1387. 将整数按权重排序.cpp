
/*
	Quick Select
*/

class Solution {

    int stepsToOne(int num) {
        int ans = 0;
        while (num > 1) {
            if (num % 2)
                num = num * 3 + 1;
            else
                num >>= 1;
            ++ans;
        }
        return ans;
    }

public:
    int getKth(int lo, int hi, int k) {
        int n = hi - lo + 1;
        int arr[n];
        for (int i = 0;i<n;++i)
            arr[i] = lo++;
        nth_element(arr, arr + k - 1, arr + n, [this](int x, int y) {
            if (stepsToOne(x) == stepsToOne(y))
                return x < y;
            return stepsToOne(x) < stepsToOne(y);
        });
        return arr[k - 1];
    }
};