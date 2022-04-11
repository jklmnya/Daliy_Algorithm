string ss[] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {

public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for (auto& w : words) {
            string str = "";
            for (auto ch : w)
                str += ss[ch - 'a'];
            s.emplace(move(str));
        }
        return s.size();
    }
};