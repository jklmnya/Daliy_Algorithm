class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = static_cast<int>(palindrome.size());
        if (n == 1)
            return "";
        bool f = false;
        for (int i = 0, mid = n >> 1;i < n;++i) {
            if (n % 2 && i == mid)
                continue;
            if (palindrome[i] > 'a') {
                palindrome[i] = 'a';
                f = true;
                break;
            }
        }
        if (!f)
            palindrome[n - 1] = 'b';
        return palindrome;
    }
};