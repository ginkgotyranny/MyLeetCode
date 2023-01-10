class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> ans(n + 1);
		ans[0] = { "" };
		ans[1] = { "()" };
		for (int i = 2; i < n + 1; i++) {
			for (int j = 0; j < i; j++) {
				for (string p : ans[j]) {
					for (string q : ans[i - j - 1]) {
						string cur = '(' + q + ')' + p;
						ans[i].push_back(cur);
					}
				}
			}
		}
		return ans[n];
	}
};