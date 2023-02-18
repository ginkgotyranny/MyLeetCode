class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> st;
		vector<int> left(heights.size());
		vector<int> right(heights.size());
		for (int i = 0; i < heights.size(); i++) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			left[i] = st.empty() ? -1 : st.top();
			st.push(i);
		}

		st = {};
		for (int i = heights.size() - 1; i >= 0; i--) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			right[i] = st.empty() ? heights.size() : st.top();
			st.push(i);
		}
		int ans = 0;
		for (int i = 0; i < heights.size(); i++) {
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};