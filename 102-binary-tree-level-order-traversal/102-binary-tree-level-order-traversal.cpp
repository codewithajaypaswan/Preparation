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
    int find_depth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(find_depth(root->left), find_depth(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = find_depth(root);
        vector<vector<int>>ans(depth);
        dfs(root, ans, 0);
        return ans;
    }
    void dfs(TreeNode* root, vector<vector<int>>&ans, int level) {
        if(!root) return;
        ans[level].push_back(root->val);
        dfs(root->left, ans, level+1);
        dfs(root->right, ans, level+1);
    }
};