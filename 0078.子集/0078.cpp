class Solution {
public:
	void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int k, int start) {
		if (cur.size() == k) {
			ans.push_back(cur);
			return;
		}

		for (int i = start; i < nums.size(); i++) {
			cur.push_back(nums[i]);
			dfs(ans, cur, nums, k, i + 1);
			cur.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> cur;
		vector<vector<int>> ans;
		for (int i = 0; i <= nums.size(); i++) {
			dfs(ans, cur, nums, i, 0);
		}
		return ans;
	}
};