class Solution {
public:
	vector<vector<int>> dict = { {-1,0},{1,0},{0,-1},{0,1} };
	
	bool dfs(vector<vector<char>>& board, string word, int cur, int row, int col, vector<vector<int>>& flag) {
		if (cur == word.length()) {
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int curRow = row + dict[i][0];
			int curCol = col + dict[i][1];
			if (curRow >= 0 && curRow < board.size() && curCol >= 0 && curCol < board[0].size() && board[curRow][curCol] == word[cur] && flag[curRow][curCol] == 0) {
				flag[curRow][curCol] = 1;
				if (dfs(board, word, cur + 1, curRow, curCol, flag)) {
					return true;
				}
				flag[curRow][curCol] = 0;
			}
		}
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<int>> flag(board.size(), vector<int>(board[0].size()));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0]) {
					flag[i][j] = 1;
					if (dfs(board, word, 1, i, j, flag)) {
						return true;
					}
					flag[i][j] = 0; 
				}
			}
		}
		return false;
	}
};