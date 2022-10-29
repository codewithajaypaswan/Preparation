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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* last = NULL;
        stack<TreeNode*>st;
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                TreeNode* node = st.top();
                if(node->right && node->right != last) {
                    root = node->right;
                }
                else {
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }
        return ans;
    }
};