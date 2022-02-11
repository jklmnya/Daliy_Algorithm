class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> vv;
        for (auto& p : points)
            vv[p[0]].insert(p[1]);
        int res = INT_MAX;
        int n = static_cast<int>(points.size());
        for (int i = 0;i<n;++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1;j<n;++j) {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 != x2 && y1 != y2) {
                    if (vv[x1].count(y2) && vv[x2].count(y1))
                        res = min(res, abs(x2 - x1) * abs(y2 - y1));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};