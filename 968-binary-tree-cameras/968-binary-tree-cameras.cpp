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
    int cam = 0;
    int minCameraCover(TreeNode* root) {
        int x = dfs(root);
        return x == -1 ? cam + 1 : cam;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int lChild = dfs(root->left);
        int rChild = dfs(root->right);
        if(lChild == -1 || rChild == -1) {
            cam++;
            return 1;
        }
        if(lChild == 1 || rChild == 1) return 0;
        return -1;
    }
};