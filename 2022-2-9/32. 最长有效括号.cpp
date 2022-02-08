class Solution {
public:

    /*
        正向 + 反向扫描
    */

    int longestValidParentheses(string ss) {
        int res = 0;
        int s = 0, n = static_cast<int>(ss.size());
        int left = 0, right = 0;
        for (int i = 0;i<n;++i) {
            if (ss[i] == '(')
                ++left;
            else
                ++right;
            if (left == right)
                res = max(res, left << 1);
            else if (right > left)
                left = right = 0;
        }
        left = 0, right = 0;
        for (int i = n - 1;i>=0;--i) {
            if (ss[i] == '(')
                ++left;
            else
                ++right;
            if (left == right)
                res = max(res, left << 1);
            else if (right < left)
                left = right = 0;
        }
        return res;
    }
};