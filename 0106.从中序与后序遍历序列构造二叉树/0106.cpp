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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        int val = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(val);
        auto it = find(inorder.begin(), inorder.end(), val);
        vector<int> left(inorder.begin(), it);
        vector<int> right(it + 1, inorder.end());
        postorder.pop_back();
        root->right = buildTree(right, postorder);
        root->left = buildTree(left, postorder);
        return root;
    }
};