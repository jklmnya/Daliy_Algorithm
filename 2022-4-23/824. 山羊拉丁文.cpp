class Solution {

    inline bool check(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    string toGoatLatin(string sentence) {
        string res = "";
        int s = 0, n = static_cast<int>(sentence.size());
        int idx = 0;
        while (s < n) {
            int e = s + 1;
            ++idx;
            while (e < n && sentence[e] != ' ') 
                ++e;
            string now = "";
            if (check(sentence[s])) {
                now = sentence.substr(s, e - s);
            } else {
                now = sentence.substr(s + 1, e - s - 1);
                now += sentence[s];
            }
            now += "ma";
            for (int i = 0;i<idx;++i)
                now += 'a';
            res += now;
            res += ' ';
            s = e + 1;
        }
        res.pop_back();
        return res;
    }
};