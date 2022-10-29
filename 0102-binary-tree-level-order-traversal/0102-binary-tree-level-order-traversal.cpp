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
    int find(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(find(root->left), find(root->right));
    }
    void dfs(TreeNode* root, int level, vector<vector<int>>&ans) {
        if(!root) return;
        ans[level].push_back(root->val);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = find(root);
        vector<vector<int>>ans(depth);
        dfs(root, 0, ans);
        return ans;
    }
};