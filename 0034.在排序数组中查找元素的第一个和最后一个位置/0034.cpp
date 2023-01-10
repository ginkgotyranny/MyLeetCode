class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target), last(nums,target)};
    }

    int first(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if ((mid == 0) || (nums[mid-1] != target)) { // 找到第一个与 target 相等的元素
                    return mid;
                }
                high = mid - 1;
            }
        }
        return -1;
    }

    int last(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if ((mid == nums.size()-1) || (nums[mid+1] != target)) { // 找到第一个与 target 相等的元素
                    return mid;
                }
                low = mid + 1;
            }
        }
        return -1;
    }
};