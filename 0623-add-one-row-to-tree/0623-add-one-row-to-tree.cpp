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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        for(int i=0; i<depth-2; i++) {
            int sz = q.size();
            while(sz--) {
                TreeNode* cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            
            TreeNode* temp = cur->left;
            cur->left = new TreeNode(val);
            cur->left->left = temp;

            temp = cur->right;
            cur->right = new TreeNode(val);
            cur->right->right = temp;
        }
        return root;
    }
};