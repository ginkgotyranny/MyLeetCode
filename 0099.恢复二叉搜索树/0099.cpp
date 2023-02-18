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
	TreeNode* t1;
	TreeNode* t2;
	TreeNode* pre;

	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		dfs(root->left);
		if (pre != nullptr && pre->val >= root->val) {
			if (t1 == nullptr) {
				t1 = pre;
			}
			t2 = root;
		}
		pre = root;
		dfs(root->right);
	}

	void recoverTree(TreeNode* root) {
		
        dfs(root);
		int tmp = t1->val;
		t1->val = t2->val;
		t2->val = tmp;
	}
};