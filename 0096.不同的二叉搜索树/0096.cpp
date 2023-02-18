class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			int count = i - 1;
			for (int j = 0; j <= count; j++) {
				dp[i] += dp[j] * dp[count - j];
			}
		}
		return dp[n];
	}
};