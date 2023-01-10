class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numsForCount;
        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (numsForCount.count(another)) {
                return { i,numsForCount[another] };
            }
            numsForCount[nums[i]] = i;
        }
        return {};
    }
};