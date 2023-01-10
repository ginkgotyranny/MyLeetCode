class Solution {
public:
	bool isMatch(string s, string p) {
		int lens = s.length();
		int lenp = p.length();
		vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
		dp[0][0] = true;
		for (int i = 1; i < lenp + 1; i++) {
			if (p[i - 1] == '*') {
				dp[0][i] = dp[0][i - 1];
			}
		}

		for (int i = 1; i < lens + 1; i++) {
			for (int j = 1; j < lenp + 1; j++) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
				}
			}
		}

		return dp[lens][lenp];
	}
};