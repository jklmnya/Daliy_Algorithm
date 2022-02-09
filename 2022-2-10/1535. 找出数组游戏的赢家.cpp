class Solution {
public
    int getWinner(vectorint& arr, int k) {
        int n = static_castint(arr.size());
        int x = arr[0], cnt = 0, maxVal = arr[0];
        queueint q;
        for (int i = 1;in;++i) {
            q.push(arr[i]);
            maxVal = max(maxVal, arr[i]);
        }
        while (q.size()) {
            int num = q.front();
            q.pop();
            if (num == maxVal)
                return maxVal;
            if (x  num) {
                q.push(num);
                if (++cnt == k)
                    return x;
            } else {  
                if (k == 1) {
                    return num;
                } else {
                    q.push(x);
                    x = num;
                    cnt = 1;
                }  
            }
        }   
        return maxVal;
    }
};