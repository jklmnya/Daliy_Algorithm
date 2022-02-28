class Solution {

    void fun(string& ss, int& x, int& y) {
        int s = 0;
        while (ss[s] != '+')
            ++s;
        x = stoi(ss.substr(0, s));
        y = stoi(ss.substr(s + 1));
    }

public:
    string complexNumberMultiply(string num1, string num2) {
        int x1, x2, y1, y2;
        fun(num1, x1, y1);
        fun(num2, x2, y2);
        string res = "";
        res += to_string(x1 * x2 - y1 * y2);
        res += '+';
        res += to_string(x1 * y2 + x2 * y1);
        res += 'i';
        return res;
    }
};