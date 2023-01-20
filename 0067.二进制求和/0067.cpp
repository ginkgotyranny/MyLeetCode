class Solution {
public:
	string addBinary(string a, string b) {
		int lena = a.length() - 1;
		int lenb = b.length() - 1;
		int count = 0;
		string ans;
		while (lena >= 0 || lenb >= 0 || count > 0) {
			char numa = lena >= 0 ? a[lena] : '0';
			char numb = lenb >= 0 ? b[lenb] : '0';
			int cur = (numa - '0') + (numb - '0') + count;
			int num = cur % 2;
			count = cur / 2;
			lena--;
			lenb--;
			ans = to_string(num) + ans;
		}

		return ans;
	}
};