class Solution {
private:
	bool row[9][9];
	bool col[9][9];
	bool subbox[3][3][9];
	bool valid;
	vector<pair<int, int>> spaces;
public:
	void dfs(vector<vector<char>>& board, int pos) {
		if (pos == spaces.size()) {
			valid = true;
			return;
		}

		for (int dig = 1; dig <= 9 && !valid; dig++) {
			pair<int, int> ind = spaces[pos];
			if (!row[ind.first][dig - 1] && !col[ind.second][dig - 1] && !subbox[ind.first / 3][ind.second / 3][dig - 1]) {
				row[ind.first][dig - 1] = col[ind.second][dig - 1] = subbox[ind.first / 3][ind.second / 3][dig - 1] = true;
				board[ind.first][ind.second] = dig + '0';
				dfs(board, pos + 1);
				row[ind.first][dig - 1] = col[ind.second][dig - 1] = subbox[ind.first / 3][ind.second / 3][dig - 1] = false;
			}
		}
	}

	void solveSudoku(vector<vector<char>>& board) {
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));
		memset(subbox, false, sizeof(subbox));
		valid = false;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int index = board[i][j] - '0' - 1;
					row[i][index] = true;
					col[j][index] = true;
					subbox[i / 3][j / 3][index] = true;
				}
				else {
					spaces.push_back({ i,j });
				}
			}
		}
		dfs(board, 0);
	}
};