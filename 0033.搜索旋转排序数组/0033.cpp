class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        seachNum(0, nums.size() - 1, nums, target, index);
        return index;
    }
    void seachNum(int left, int right, vector<int>& nums, int target, int& index) {
        if (nums[left] == target) {
            index = left;
            return;
        }
        if (right - left <= 0) {
            return;
        }
        int middle = (left + right) / 2;
        seachNum(left, middle, nums, target, index);
        seachNum(middle + 1, right, nums, target, index);
        return;
    }
};

// 二分查找
int binarySearchMatrix(vector<int>& nums, int target) {
	int low = 0;
    int high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] > target) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}

// 二分查找第一个与 target 相等的元素，时间复杂度 O(logn)
int searchFirstEqualElement(vector<int>& nums, int target) {
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

// 二分查找最后一个与 target 相等的元素，时间复杂度 O(logn)
int searchLastEqualElement(vector<int>& nums, int target) {
	int low = 0;
    int high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] > target) {
			high = mid - 1;
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			if ((mid == len(nums)-1) || (nums[mid+1] != target)) { // 找到最后一个与 target 相等的元素
				return mid;
			}
			low = mid + 1;
		}
	}
	return -1;
}

// 二分查找第一个大于等于 target 的元素，时间复杂度 O(logn)
int searchFirstGreaterElement(vector<int>& nums, int target) {
	int low = 0;
    int high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] >= target) {
			if ((mid == 0) || (nums[mid-1] < target)) { // 找到第一个大于等于 target 的元素
				return mid;
			}
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1
}

// 二分查找最后一个小于等于 target 的元素，时间复杂度 O(logn)
int searchLastLessElement(vector<int>& nums, int target) {
	int low = 0;
    int high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] <= target) {
			if ((mid == len(nums)-1) || (nums[mid+1] > target)) { // 找到最后一个小于等于 target 的元素
				return mid;
			}
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1
}