class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		int m = num1.length();
		int n = num2.length();
		vector<int> nums(m + n);
		for (int i = m - 1; i >= 0; i--) {
			int cur1 = num1[i] - '0';
			for (int j = n - 1; j >= 0; j--) {
				int cur2 = num2[j] - '0';
				nums[i + j + 1] += cur1 * cur2;
			}
		}

		for (int i = m + n - 2; i >= 0; i--) {
			nums[i] += nums[i + 1] / 10;
			nums[i + 1] %= 10;
		}

		int index = nums[0] == 0 ? 1 : 0;

		string ans;
		for (int i = index; i < m + n; i++) {
			ans = ans + to_string(nums[i]);
		}
		return ans;
	}
};