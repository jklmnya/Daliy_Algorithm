class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ss;
        for (auto& b : banned) {
            for (char& ch : b)
                ch = tolower(ch);
            ss.emplace(move(b));
        }
        int s = 0, n = static_cast<int>(paragraph.size());
        unordered_map<string, int> vv;
        while (s < n) {
            if ((paragraph[s] >= 'a' && paragraph[s] <= 'z') || (paragraph[s] >= 'A' && paragraph[s] <= 'Z')) {
                paragraph[s] = tolower(paragraph[s]);
                int e = s + 1;
                while (e < n && ((paragraph[e] >= 'a' && paragraph[e] <= 'z') || (paragraph[e] >= 'A' && paragraph[e] <= 'Z'))) {
                    paragraph[e] = tolower(paragraph[e]);
                    ++e;
                }
                string word = paragraph.substr(s, e - s);
                if (!ss.count(word))
                    ++vv[word];
                s = e;
            } else {
                ++s;
            }
        }
        string res = "";
        int f = 0;
        for (auto&& [ans, cnt] : vv) {
            if (cnt > f) {
                f = cnt;
                res = ans;
            }
        }
        return res;
    }
};