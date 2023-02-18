class Solution {
public:
	int numDecodings(string s) {
		map<string,int> res;
		for (int i = 1; i <= 26; i++) {
			res[to_string(i)]++;
		}
		int n = s.length();
		vector<int> dp(n + 1);
		if (s[0] == '0') {
			return 0;
		}
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			string tmp1 = s.substr(i - 1, 1);
			string tmp2 = s.substr(i - 2, 2);
			if (res.count(tmp1) == 0 && res.count(tmp2) == 0) {
				return 0;
			}
			if (res.count(tmp1) != 0) {
				dp[i] += dp[i - 1];
			}
			if (res.count(tmp2) != 0) {
				dp[i] += dp[i - 2];
			}
		}
		return dp[n];
	}
};