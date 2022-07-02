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
    string ans = "|";
    void dfs(TreeNode* root, string str) {
        if(!root) return;
        str += (char)(root->val + 'a');
        if(!root->left && !root->right) {
            reverse(str.begin(), str.end());
            ans = min(ans, str);
        }
        dfs(root->left, str);
        dfs(root->right, str);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};