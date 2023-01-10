class Solution {
public:
	string countAndSay(int n) {
		int index = n - 1;
		string ans = "1";

		while (index) {
			char cur = ans[0];
			int count = 0;
			string res = "";
			for (auto c : ans) {
				if (cur == c) {
					count++;
				}
				else {
					res += to_string(count);
					res += cur;
					cur = c;
					count = 1;
				}
			}
			res += to_string(count);
			res += cur;
			ans = res;
			index--;
		}
		return ans;
	}
};