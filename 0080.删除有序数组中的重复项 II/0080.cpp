class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int index = 1;
		int curNum = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == curNum) {
				count++;
			}
			else {
				curNum = nums[i];
				count = 1;
			}
			if (count <= 2) {
				nums[index] = nums[i];
				index++;
			}
		}
		return index;
	}
};