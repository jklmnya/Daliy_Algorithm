class Solution {

    static constexpr int X = 100;

public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int f = 0;
        int res1 = 0;
        for (char ch : s) {
            if (f + widths[ch - 'a'] > X) {
                ++res1;
                f = widths[ch - 'a'];
            } else {
                f += widths[ch - 'a'];
            }
        }
        if (f == 0)
            return { res1, f };
        else
            return { res1 + 1, f };
    }
};