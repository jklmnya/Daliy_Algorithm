class Solution {

	int res;
	int now;

	void dfs(int idx, int ans, vector<int>& nums) {
		if (idx == static_cast<int>(nums.size())) {
			if (ans == now) {
				++res;
			}
			else if (ans > now) {
				now = ans;
				res = 1;
			}
			return;
		}
		dfs(idx + 1, ans, nums);
		dfs(idx + 1, ans | nums[idx], nums);
	}

public:
	int countMaxOrSubsets(vector<int>& nums) {
		vector<int> vv;
		dfs(0, 0, nums);
		return res;
	}
};