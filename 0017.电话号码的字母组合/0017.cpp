class Solution {
public:
	map<char, string> phoneMap {
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
	};

	void fun(string& digits, vector<string>& ans, int index, string& cur) {
		if (index == digits.length()) {
			ans.push_back(cur);
			return;
		}
		string maps = phoneMap[digits[index]];
		for (int i = 0; i < maps.length(); i++) {
			cur += maps[i];
			fun(digits, ans, index + 1, cur);
			cur.erase(cur.end() - 1);
		}
		return;
	}

	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		string cur = "";
        if(digits.length() == 0){
            return ans;
        }
		fun(digits, ans, 0, cur);
		return ans;
	}
};