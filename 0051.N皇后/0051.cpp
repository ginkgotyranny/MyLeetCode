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

    void fun(vector<vector<int>>& flagMatrix, vector<vector<string>>& ans, vector<string>& res, int n, int row, int col) {
        if (n == 0) {
            ans.push_back(res);
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
                    res[i][j] = 'Q';
                    fun(flagMatrix, ans, res, n - 1, i, j);
                    play(flagMatrix, i, j, -1);
                    res[i][j] = '.';
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans = {};
        vector<string> res = {};
        string cur = "";
        for (int i = 0; i < n; i++) {
            cur += '.';
        }
        for (int i = 0; i < n; i++) {
            res.push_back(cur);
        }
        vector<vector<int>> flagMatrix(n, vector<int>(n, 0));
        fun(flagMatrix, ans, res, n, 0, 0);
        return ans;
    }
};