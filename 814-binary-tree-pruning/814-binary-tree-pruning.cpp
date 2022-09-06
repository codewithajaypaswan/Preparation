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
    TreeNode* dfs(TreeNode* root) {
        if(!root) return root;
        TreeNode* cur = new TreeNode(root->val);
        cur->left = dfs(root->left);
        cur->right = dfs(root->right);
        if(!cur->left && !cur->right && cur->val == 0) return NULL;
        return cur;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
};