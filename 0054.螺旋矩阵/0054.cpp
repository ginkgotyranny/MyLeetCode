class Solution {
public:
	vector<pair<int, int>> dict = { {0,1},{1,0},{0,-1},{-1,0} };
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int left = 0;
		int right = matrix[0].size() - 1;
		int up = 0;
		int down = matrix.size() - 1;
		int row = 0;
		int col = 0;
		int count = 0;
		int flag = -1;
		vector<int> ans;
		while (count < matrix.size() * matrix[0].size()) {
			if(flag == -1) {
                flag++;
                up++;
            }
            if (flag == 0 && col == right) {
				flag++;
				right--;
			}
			else if (flag == 1 && row == down) {
				flag++;
				down--;
			}
			else if (flag == 2 && col == left) {
				flag++;
				left++;
			}
			else if (flag == 3 && row == up) {
				flag++;
				up++;
			}
			flag %= 4;
            
            ans.push_back(matrix[row][col]);
			row += dict[flag].first;
			col += dict[flag].second;
			count++;
            
		}
		return ans;
	}
};