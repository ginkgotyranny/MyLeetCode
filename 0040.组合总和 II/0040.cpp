class Solution {
public:
	void dfs(vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& ans, int sum, int start) {
		if (sum > target) {
			return;
		}
		if (sum == target) {
			ans.push_back(cur);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (i != start && candidates[i] == candidates[i - 1]) {
				continue;
			}
			cur.push_back(candidates[i]);
			dfs(candidates, target, cur, ans, sum + candidates[i], i + 1);
			cur.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> cur;
		vector<vector<int>> ans;
		dfs(candidates, target, cur, ans, 0, 0);
		return ans;
	}
};