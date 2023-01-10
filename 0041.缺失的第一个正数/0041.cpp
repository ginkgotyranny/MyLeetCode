class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int index = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < index) {
				continue;
			}
			else if (nums[i] == index) {
				index++;
			}
			else {
				return index;
			}
		}
		return index;
	}
};