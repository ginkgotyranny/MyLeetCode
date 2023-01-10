class Solution {
public:
	bool canJump(vector<int>& nums) {
		int latter = 0;
		int fast = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i + nums[i] > fast) {
				fast = i + nums[i];
			}
			if (i == latter) {
				latter = fast;
			}
			if (latter >= nums.size() - 1) {
				return true;
			}
		}
		return false;
	}
};