class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLen = nums1.size() + nums2.size();
        if (totalLen % 2 == 1) {
            return FindTargetNum(nums1, nums2, totalLen / 2 + 1);
        }
        return (FindTargetNum(nums1, nums2, totalLen / 2) + FindTargetNum(nums1, nums2, totalLen / 2 + 1)) / 2.0;
    }

    double FindTargetNum(vector<int>& nums1, vector<int>& nums2, int target) {
        int index = 1;
        int targetNum = 0;
        int nums1Index = 0;
        int nums2Index = 0;
        while (index <= target) {
            int num1 = nums1Index < nums1.size() ? nums1[nums1Index] : INT_MAX;
            int num2 = nums2Index < nums2.size() ? nums2[nums2Index] : INT_MAX;
            if (num1 <= num2) {
                targetNum = num1;
                nums1Index++;
            }
            else {
                targetNum = num2;
                nums2Index++;
            }
            index++;
        }
        return targetNum;
    }
};