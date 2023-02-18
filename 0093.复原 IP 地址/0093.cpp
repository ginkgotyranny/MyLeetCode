class Solution {
public:
	void dfs(string s, vector<string>& ans, vector<string>& cur) {
		if (cur.size() == 4 && s == "") {
			string res = cur[0] + '.' + cur[1] + '.' + cur[2] + '.' + cur[3];
			ans.push_back(res);
			return;
		}
		for (int len = 1; len <= 3; len++) {
			if (len > 1 && s[0] == '0') {
				break;
			}
			if (s.length() < len) {
				break;
			}
			string tmpStr = s.substr(0, len);
			int tmpNum = stoi(tmpStr);
			if (tmpNum >= 0 && tmpNum <= 255) {
				cur.push_back(tmpStr);
				dfs(s.substr(len), ans, cur);
				cur.pop_back();
			}
		}
		return;
	}

	vector<string> restoreIpAddresses(string s) {
		int len = s.length();
		if (len < 4 || len > 12) {
			return {};
		}
		vector<string> ans;
		vector<string> cur;
		dfs(s, ans, cur);
		return ans;
	}
};