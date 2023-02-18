class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		ans.push_back(1);
		for (int i = 2; i <= n; i++) {
			for (int j = ans.size() - 1; j >= 0; j--) {
				ans.push_back(ans[j] + pow(2, i - 1));
			}
		}
		return ans;
	}
};
