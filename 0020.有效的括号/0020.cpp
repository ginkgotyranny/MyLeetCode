class Solution {
public:
	bool isValid(string s) {
		map<char, char> mp{ {')','('},{'}','{'},{']','['} };
		if (s.length() <= 1) {
			return false;
		}
		stack<char> stk;
		stk.push('$');
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				stk.push(s[i]);
			}
			else if (mp[s[i]] == stk.top()) {
				stk.pop();
			}
			else {
				return false;
			}
		}
		return stk.size() == 1;
	}
};