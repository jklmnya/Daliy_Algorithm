class Solution {

    int fun(string& str, char ch, int k) {
        int s = 0, e = 0, n = static_cast<int>(str.size());
        int res = 0;
        while (e < n) {
            while (e < n && k) {
                if (str[e] == ch)
                    --k;
                ++e;
            }
            while (e < n && str[e] != ch)
                ++e;
            res = max(res, e - s);
            while (s < e && str[s] != ch)
                ++s;
            ++s;
            ++k;
        }
        return res;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(fun(answerKey, 'T', k), fun(answerKey, 'F', k));
    }
};