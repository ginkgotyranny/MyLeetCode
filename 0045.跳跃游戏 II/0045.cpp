class Solution {
public:
	int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
		int fast = 0;
		int last = nums[0];
		int count = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (last >= nums.size() - 1) {
				return count;
			}
			if (i + nums[i] > fast) {
				fast = i + nums[i];
			}
            if(i == last){
                last = fast;
                count++;
            }
		}
		return count;
	}
};