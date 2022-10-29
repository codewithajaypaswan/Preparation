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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* cur = dummy;
        dfs(root, cur);
        return dummy->right;
    }
    void dfs(TreeNode* root, TreeNode* &cur) {
        if(!root) return;
        dfs(root->left, cur);
        root->left = NULL;
        cur->right = root;
        cur = cur->right;
        dfs(root->right, cur);
    }
};