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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		}
		int pVal = p == nullptr ? INT_MAX : p->val;
		int qVal = q == nullptr ? INT_MAX : q->val;
		if (pVal != qVal) {
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};