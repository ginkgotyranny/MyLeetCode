class Solution {
public:
	vector<vector<int>> dict = { {0,1},{1,0},{0,-1},{-1,0} };

	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n));
		int up = 0;
		int down = n - 1;
		int left = 0;
		int right = n - 1;
		int row = 0;
		int col = -1;
		int flag = -1;

		for (int i = 0; i < n * n; i++) {
			if (flag == -1) {
				flag++;
				up++;
			}
			if (flag == 0 && col == right) {
				flag++;
				right--;
			}
			if (flag == 1 && row == down) {
				flag++;
				down--;
			}
			if (flag == 2 && col == left) {
				flag++;
				left++;
			}
			if (flag == 3 && row == up) {
				flag++;
				up++;
			}
			flag %= 4;
			row += dict[flag][0];
			col += dict[flag][1];
			matrix[row][col] = i + 1;
		}
		return matrix;
	}
};