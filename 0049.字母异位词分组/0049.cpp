class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> mp;
		for (int i = 0; i < strs.size(); i++) {
			string cur = strs[i];
			sort(strs[i].begin(), strs[i].end());
			mp[strs[i]].push_back(cur);
		}
		vector<vector<string>> ans;
		for (auto it : mp) {
			ans.push_back(it.second);
		}
		return ans;
	}
};