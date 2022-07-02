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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()) {
            int l = q.front().second;
            int r = l, sz = q.size();
            while(sz--) {
                auto it = q.front(); q.pop();
                TreeNode* cur = it.first;
                r = it.second;
                if(cur->left) q.push({cur->left, 1LL * 2*r+1});
                if(cur->right) q.push({cur->right, 1LL * 2*r+2});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};