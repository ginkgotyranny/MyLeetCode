class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int count = 1;
		for (int i = digits.size() - 1; i >= 0; i--) {
			int tmp = count + digits[i];
			digits[i] = tmp % 10;
			count = tmp / 10;
		}
		if (count != 0) {
			digits.insert(digits.begin(), count);
		}
		return digits;
	}
};