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
	bool dfs(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {
			return true;
		}
		int leftNum = left == nullptr ? 200 : left->val;
		int rightNum = right == nullptr ? 200 : right->val;
		if (leftNum != rightNum) {
			return false;
		}
		return dfs(left->left, right->right) && dfs(left->right, right->left);
	}

	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		return dfs(root->left, root->right);
	}
};