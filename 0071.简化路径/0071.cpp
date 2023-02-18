class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dq;
		string cur = "";
		for (int i = 0; i < path.length(); i++) {
			if (path[i] == '/') {
				if (cur == "..") {
					if (!dq.empty()) {
						dq.pop_back();
					}
					cur = "";
					continue;
				}
				else if (cur == "." || cur == "") {
					cur = "";
					continue;
				}
				dq.push_back(cur);
				cur = "";
			}
			else {
				cur += path[i];
			}
		}

		if (!cur.empty()) {
			if (cur == "..") {
				if (!dq.empty()) {
					dq.pop_back();
				}
			}
			else if (cur != ".") {
				dq.push_back(cur);
			}
		}

		string ans;
		for (int i = 0; i < dq.size(); i++) {
			ans += "/" + dq[i];
		}
		if (ans.size() == 0) {
			return "/";
		}
		return ans;
	}
};