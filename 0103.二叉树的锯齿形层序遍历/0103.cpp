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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans = {};
        if (root == nullptr) {
            return ans;
        }
        int flag = -1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> res;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            flag *= -1;
            if (flag == -1) {
                reverse(res.begin(), res.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};