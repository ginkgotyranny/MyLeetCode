class Solution {
public:
	void dfs(vector<vector<int>>& ans, vector<int>& cur, int n, int k, int start) {
		if (cur.size() == k) {
			ans.push_back(cur);
			return;
		}

		for (int i = start; i <= n; i++) {
			cur.push_back(i);
			dfs(ans, cur, n, k, i + 1);
			cur.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int> cur;
		vector<vector<int>> ans;
		dfs(ans, cur, n, k, 1);
		return ans;
	}
};