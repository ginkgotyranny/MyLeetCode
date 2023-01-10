class Solution {
public:
	void play(vector<vector<int>>& flagMatrix, int i, int j, int flag) {
		int row = i;
		int col = j;
		for (; row < flagMatrix.size(); row++) {
			flagMatrix[row][j] += flag;
			if (col >= 0) {
				flagMatrix[row][col] += flag;
				col--;
			}
		}
		row = i;
		col = j;
		for (; col < flagMatrix[0].size(); col++) {
			flagMatrix[i][col] += flag;
			if (row < flagMatrix.size()) {
				flagMatrix[row][col] += flag;
				row++;
			}
		}
	}

	void dfs(vector<vector<int>>& flagMatrix, int& count, int n, int row, int col) {
		if (n == 0) {
			count++;
			return;
		}
		for (int i = 0; i < flagMatrix.size(); i++) {
			if (i < row) {
				continue;
			}
			for (int j = 0; j < flagMatrix[0].size(); j++) {
				if (i == row && j < col) {
					continue;
				}
				if (flagMatrix[i][j] == 0) {
					play(flagMatrix, i, j, 1);
					dfs(flagMatrix, count, n - 1, i, j);
					play(flagMatrix, i, j, -1);
				}
			}
		}
	}

	int totalNQueens(int n) {
		int count = 0;
		vector<vector<int>> flagMatrix(n, vector<int>(n, 0));
		dfs(flagMatrix, count, n, 0, 0);
		return count;
	}
};