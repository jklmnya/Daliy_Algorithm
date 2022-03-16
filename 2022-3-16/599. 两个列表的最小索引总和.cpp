class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> vv;
        int i = 0, now = INT_MAX;
        for (auto& l : list1)
            vv.emplace(move(l), i++);
        for (int i = 0;i<list2.size();++i) {
            if (vv.count(list2[i])) {
                if (vv[list2[i]] + i < now) {
                    now = vv[list2[i]] + i;
                    res.clear();
                    res.push_back(move(list2[i]));
                } else if (vv[list2[i]] + i == now) {
                    res.push_back(move(list2[i]));
                }
            }
        }
        return res;
    }
};