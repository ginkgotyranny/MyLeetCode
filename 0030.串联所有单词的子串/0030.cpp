class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		int m = words.size();
		int n = words[0].length();
		int ls = s.length();

		for (int i = 0; i < n && i + m * n <= ls; i++) {
			map<string, int> mp;
			for (int j = 0; j < m; j++) {
				mp[s.substr(i + j * n, n)]++;
			}

			for (string word : words) {
				mp[word]--;
				if (mp[word] == 0) {
					mp.erase(word);
				}
			}

			for (int start = i; start < ls - m * n + 1; start += n) {
				if (start != i) {
					string word = s.substr(start - n, n);
					mp[word]--;
					if (mp[word] == 0) {
						mp.erase(word);
					}
					word = s.substr(start + n * (m - 1), n);
					mp[word]++;
					if (mp[word] == 0) {
						mp.erase(word);
					}
				}

				if (mp.empty()) {
					ans.push_back(start);
				}
			}
		}
		return ans;
	}
};