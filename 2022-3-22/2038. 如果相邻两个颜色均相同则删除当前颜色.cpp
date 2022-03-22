class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = static_cast<int>(colors.size());
        int a = 0, b = 0;
        int s = 0;
        while (s < n) {
            int e = s;
            while (e < n && colors[e] == colors[s])
                ++e;
            if (colors[s] == 'A')
                a += max(0, e - s - 2);
            else
                b += max(0, e - s - 2);
            s = e;
        }
        return a > b;
    }
};