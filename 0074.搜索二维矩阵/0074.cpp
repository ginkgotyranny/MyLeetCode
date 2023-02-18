class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0;
		int j = 0;
		for (; i < row; i++) {
			if (matrix[i][0] == target) {
				return true;
			}
			if (matrix[i][0] > target) {
				break;
			}
		}
		if (i == 0) {
			return false;
		}
		i--;
		for (; j < col; j++) {
			if (matrix[i][j] == target) {
				return true;
			}
		}
		return false;
	}
};