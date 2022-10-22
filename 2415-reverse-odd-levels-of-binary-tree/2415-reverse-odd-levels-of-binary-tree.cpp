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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        vector<int>value;
        while(!q.empty()) {
            int sz = q.size();
            vector<int>temp;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                if(level%2 == 1) {
                    cur->val = value[sz - 1 - i];
                }
                if(cur->left) {
                    q.push(cur->left);
                    temp.push_back(cur->left->val);    
                }
                if(cur->right) {
                    q.push(cur->right);
                    temp.push_back(cur->right->val);
                }
            }
            value = temp;
            level++;
        }
        return root;
    }
};