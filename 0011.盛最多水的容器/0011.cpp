class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int dep = min(height[left], height[right]);
            maxA = max(maxA, dep * (right - left));
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxA;
    }
};