class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 && nums[0] > target) {
            return ans;
        }
        if (nums[nums.size() - 1] < 0 && nums[nums.size() - 1] < target) {
            return ans;
        }
        for (int first = 0; first < nums.size() - 1; first++) {	
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            for (int second = first + 1; second < nums.size(); second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                long cur = (long)target - nums[first] - nums[second];
                for (int third = second + 1; third < nums.size(); third++) {
                    if (nums[third] > 0 && nums[third] > cur) {
                        break;
                    }
                    if (third > second + 1 && nums[third] == nums[third - 1]) {
                        continue;
                    }
                    int forth = nums.size() - 1;
                    while (third < forth && nums[third] + nums[forth] > cur) {
                        forth--;
                    }
                    if (third == forth) {
                        break;
                    }
                    if (nums[third] + nums[forth] == cur) {
                        ans.push_back({ nums[first],nums[second],nums[third],nums[forth] });
                    }
                }
            }
        }
        return ans;
    }
};