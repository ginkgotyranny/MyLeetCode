class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> left = height;
		vector<int> right = height;
		int count = 0;
		for (int i = 1; i < height.size(); i++) {
			left[i] = max(left[i], left[i - 1]);
		}
		for (int i = height.size() - 2; i >= 0; i--) {
			right[i] = max(right[i], right[i + 1]);
		}
		for (int i = 0; i < height.size(); i++) {
			count += min(left[i], right[i]) - height[i];
		}
		return count;
	}
};