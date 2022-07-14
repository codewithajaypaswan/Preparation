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
    int preInd = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, mp, 0, preorder.size()-1);
    }
    TreeNode* solve(vector<int>&preorder, unordered_map<int,int>&mp, int low, int high) {
        if(low > high) return NULL;
        TreeNode* root = new TreeNode(preorder[preInd]);
        int mid = mp[preorder[preInd]];
        preInd++;
        root->left = solve(preorder, mp, low, mid-1);
        root->right = solve(preorder, mp, mid+1, high);
        return root;
    }
};