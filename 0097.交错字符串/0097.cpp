class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if (len1 + len2 != len3) {
			return false;
		}
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		dp[0][0] = true;

		for (int i = 0; i <= len1; i++) {
			for (int j = 0; j <= len2; j++) {
				int index = i + j - 1;
				if (i > 0) {
					dp[i][j] = dp[i][j] | (s3[index] == s1[i - 1] && dp[i - 1][j]);
				}
				if (j > 0) {
					dp[i][j] = dp[i][j] | (s3[index] == s2[j - 1] && dp[i][j - 1]);
				}
			}
		}
		return dp[len1][len2];
	}
};