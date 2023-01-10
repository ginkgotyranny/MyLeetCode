class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = 0;
		int mingap = INT_MAX;
		for (int first = 0; first < nums.size(); first++) {
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}		
			for (int second = first + 1; second < nums.size(); second++) {
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				int third = nums.size() - 1;
				int cur = target - nums[first] - nums[second];
				while (third > second) {
					if (abs(nums[third] - cur) < mingap) {
						mingap = abs(nums[third] - cur);
						ans = nums[first] + nums[second] + nums[third];
					}
					third--;
				}
			}
		}
		return ans;
	}
};