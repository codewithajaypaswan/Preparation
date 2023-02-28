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
    unordered_map<string, vector<TreeNode*>>mp;
    string solve(TreeNode* root) {
        if(!root) return "";
        string temp = "(" + solve(root->left) + to_string(root->val) + solve(root->right) + ")";
        mp[temp].push_back(root);
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) { 
        solve(root);
        vector<TreeNode*>ans;
        for(auto it:mp) {
            if(it.second.size() > 1) {
                ans.push_back(it.second[0]);
            }
        }
        return ans;
    }
};