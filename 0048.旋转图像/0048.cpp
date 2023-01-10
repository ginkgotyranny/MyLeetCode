class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        vector<vector<int>> newmatrix(row, vector<int>(row));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                newmatrix[j][row-i-1] = matrix[i][j];
            }
        }
        matrix = newmatrix;

    }
};