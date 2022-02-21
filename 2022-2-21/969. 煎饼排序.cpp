class Solution {
public
    vectorint pancakeSort(vectorint& arr) {
        int n = static_castint(arr.size());
        vectorint res;
        for (int i = n;i=1;--i) {
            int j = 0;
            while (j  n && arr[j] != i)
                ++j;
            if (j != i - 1) {
                res.push_back(j + 1);
                reverse(arr.begin(), arr.begin() + j + 1);
                res.push_back(i);
                reverse(arr.begin(), arr.begin() + i);
            }
        }
        return res;
    }
};