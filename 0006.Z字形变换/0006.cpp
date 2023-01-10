class Solution {
public:
    string convert(string s, int numRows) {
        int flag = -1;
        int row = 0;
        if (numRows < 2) {
            return s;
        }
        vector<string> rowNums(numRows);
        for (int i = 0; i < s.length(); i++) {
            if (row == 0 || row == numRows - 1) {
                flag *= -1;
            }
            rowNums[row] += s[i];
            row += flag;
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            ans += rowNums[i];
        }
        return ans;
    }
};