class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int left = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				count++;
				continue;
			}
			nums[left] = nums[i];
			left++;
		}
		return nums.size() - count;
	}
};