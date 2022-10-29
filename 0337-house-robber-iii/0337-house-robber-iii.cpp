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
    unordered_map<TreeNode*, int>mp;
    int solve(TreeNode* root) {
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int rob = root->val, notRob = 0;
        if(root->left) {
            rob += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right) {
            rob += solve(root->right->left) + solve(root->right->right);
        }
        notRob += solve(root->left) + solve(root->right);
        return mp[root] = max(rob, notRob);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};