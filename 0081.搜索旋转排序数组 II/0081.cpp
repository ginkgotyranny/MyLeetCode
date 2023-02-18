class Solution {
public:
	bool search(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int middle = (left + right) / 2;
			if (nums[middle] == target) {
				return true;
			}
			else if (nums[middle] < target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return false;
	}
};