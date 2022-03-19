class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> ss(words.begin(), words.end());
        string res = "";
        for (auto& word : words) {
            string ans = word;
            word.pop_back();
            while (word.size() >= 1 && ss.count(word))
                word.pop_back();
            if (word.size() == 0) {
                if (ans.size() > res.size()) {
                    res = ans;
                } else if (ans.size() == res.size()) {
                    if (ans < res)
                        res = ans;
                }
            }
        }
        return res;
    }
};