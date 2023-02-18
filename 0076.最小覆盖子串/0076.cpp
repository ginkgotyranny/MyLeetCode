class Solution {
public:
	string minWindow(string s, string t) {
		map<char, int> mpt, mps;
		for (auto c : t) {
			mpt[c]++;
		}
		int maxLen = INT_MAX;
		string ans = "";
		int count = 0;
		for (int i = 0, j = 0; i < s.length(); i++) {
			mps[s[i]]++;
			if (mps[s[i]] <= mpt[s[i]]) {
				count++;
			}
			while (mps[s[j]] > mpt[s[j]]) {
				mps[s[j]]--;
				j++;
			}
			if (count == t.length()) {
				if (maxLen > i - j + 1) {
					maxLen = i - j + 1;
					ans = s.substr(j, maxLen);
				}
			}
		}
		return ans;
	}
};