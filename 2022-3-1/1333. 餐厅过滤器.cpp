class Solution {
public:
	vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
		vector<vector<int>> vv;
		for (auto& rest : restaurants) {
			if ((!veganFriendly || veganFriendly && rest[2]) && rest[3] <= maxPrice && rest[4] <= maxDistance)
				vv.push_back(move(rest));
		}
		vector<int> res(vv.size());
		sort(vv.begin(), vv.end(), [](const vector<int>& v1, const vector<int>& v2) {
			if (v1[1] == v2[1])
				return v1[0] > v2[0];
			return v1[1] > v2[1];
		});
		for (int i = 0; i < static_cast<int>(vv.size()); ++i)
			res[i] = vv[i][0];
		return res;
	}
};