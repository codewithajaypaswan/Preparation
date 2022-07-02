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
    int postInd;
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        postInd = n-1;
        return solve(postorder, 0, n-1);
    }
    TreeNode* solve(vector<int>&postorder, int low, int high) {
        if(postInd < 0 || low > high) return NULL;
        TreeNode* root = new TreeNode(postorder[postInd]);
        int mid = mp[postorder[postInd]];
        postInd--;
        root->right = solve(postorder, mid+1, high);
        root->left = solve(postorder, low, mid-1);
        return root;
    }
};