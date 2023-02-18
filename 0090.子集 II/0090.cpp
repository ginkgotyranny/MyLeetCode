class Solution {
public:
	void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, int start, int len) {
		if (cur.size() == len) {
			ans.push_back(cur);
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			if (i == start || nums[i] != nums[i - 1]) {
				cur.push_back(nums[i]);
				dfs(nums, cur, ans, i + 1, len);
				cur.pop_back();
			}
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> cur;
		vector<vector<int>> ans;
		for (int i = 0; i <= nums.size(); i++) {
			dfs(nums, cur, ans, 0, i);
		}
		return ans;
	}
};