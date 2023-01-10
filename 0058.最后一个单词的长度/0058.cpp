class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		int cur = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				len = cur;
			}
			else {
				if (i == 0 || s[i - 1] == ' ') {
					cur = 0;
				}
				cur++;
			}
		}
		return cur == 0 ? len : cur;
	}
};