#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int indx[] = { 1,0,-1,0 };
int indy[] = { 0,1,0,-1 };
int matrow = 0;
int matcol = 0;
int matrix[105][105] = {};
int lenthMatrix[105][105] = {};

int maxLenth(int matrix[105][105], int lenthMatrix[105][105], int row, int col) {
    if (lenthMatrix[row][col] != 0) {
        return lenthMatrix[row][col];
    }
    int maxlen = 1;
    for (int i = 0; i < 4; i++) {
        int nextrow = row + indx[i];
        int nextcol = col + indy[i];
        if (nextrow >= 0 && nextrow < matrow && nextcol >= 0 && nextcol < matcol && matrix[nextrow][nextcol] < matrix[row][col]) {
            maxlen = max(maxlen, maxLenth(matrix, lenthMatrix, row + indx[i], col + indy[i]) + 1);
        }
    }
    return maxlen;
}

int main()
{
    scanf_s("%d %d", &matrow, &matcol);
    for (int i = 0; i < matrow; i++) {
        for (int j = 0; j < matcol; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int maxlenth = 0;
    for (int i = 0; i < matrow; i++) {
        for (int j = 0; j < matcol; j++) {
            lenthMatrix[i][j] = maxLenth(matrix, lenthMatrix, i, j);
            maxlenth = max(maxlenth, maxLenth(matrix, lenthMatrix, i, j));
        }
    }
    printf("%d", maxlenth);
    return 0;
}
