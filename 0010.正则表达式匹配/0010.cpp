class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool> > dp(lens + 1, vector<bool>(lenp + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < lenp + 1; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i < lens + 1; i++) {
            for (int j = 1; j < lenp + 1; j++) {
                if (s[i - 1] == p[j - 1] || p[j-1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};