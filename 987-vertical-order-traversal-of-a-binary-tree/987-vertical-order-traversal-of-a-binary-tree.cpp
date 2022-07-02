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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        dfs(root, 0, 0, mp);
        vector<vector<int>>ans;
        for(auto it:mp) {
            vector<int>v;
            for(auto x:it.second) {
                v.insert(v.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>&mp) {
        if(!root) return;
        mp[x][y].insert(root->val);
        dfs(root->left, x-1, y+1, mp);
        dfs(root->right, x+1, y+1, mp);
    }
};