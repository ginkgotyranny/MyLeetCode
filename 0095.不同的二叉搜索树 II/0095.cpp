/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<TreeNode*> dfs(int start, int end) {
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*> arr;
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> left = dfs(start, i - 1);
			vector<TreeNode*> right = dfs(i + 1, end);
			for (auto l : left) {
				for (auto r : right) {
					TreeNode* head = new TreeNode(i);
					head->left = l;
					head->right = r;
					arr.push_back(head);
				}
			}
		}
		return arr;
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans;
		if (n == 0) {
			return {};
		}
		return dfs(1, n);
	}
};