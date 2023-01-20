class Solution {
public:
	bool isNumber(string s) {
		int flagdot = 1;
		int flage = 1;
		int flagdig = 0;
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] == '-' || s[i] == '+')) {
				if (i == s.length() - 1) {
					return false;
				}
				else if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
					return false;
				}
			}
			else if (s[i] == '.') {
				if (flage == 0 || flagdot == 0) {
					return false;
				}
				if (flagdig == 0) {
					if (i == s.length() - 1) {
						return false;
					}
					else if (s[i+1] - '0' < 0 || s[i+1] - '0' > 9) {
						return false;
					}
				}
				flagdot = 0;
			}
			else if (s[i] == 'e' || s[i] == 'E') {
				if (flagdig == 0 || flage == 0 || i == s.length() - 1) {
					return false;
				}
				flage = 0;
			}
			else if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
				flagdig = 1;
			}
			else {
				return false;
			}
		}
		return true;
	}
};