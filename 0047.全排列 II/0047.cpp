class Solution {
public:
    void dfs(vector<int>& nums, map<int, int>& mp, vector<int>& cur, vector<vector<int>>& ans, int pos) {
		if (pos == nums.size()) {
			ans.push_back(cur);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			if (mp.count(i) == 0 || mp[i] == 0) {
				mp[i]++;
				cur.push_back(nums[i]);
				dfs(nums, mp, cur, ans, pos + 1);
				cur.pop_back();
				mp[i]--;
			}
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> mp;
		vector<int> cur;
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		dfs(nums, mp, cur, ans, 0);
		return ans;
    }
};