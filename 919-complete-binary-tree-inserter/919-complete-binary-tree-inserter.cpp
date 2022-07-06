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
class CBTInserter {
private:
    TreeNode* root_ = nullptr;
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
    }
    
    int insert(int v) {
        // Use bfs for insertion
        queue<TreeNode*> q;
        q.push(root_);
        TreeNode* cur = nullptr;
        
        while(!q.empty()) {
            cur = q.front(); q.pop();
            
            if(!cur->left) {
                cur->left = new TreeNode(v);
                break;
            }
            if(!cur->right) {
                cur->right = new TreeNode(v);
                break;
            }
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return cur->val;
    }
    
    TreeNode* get_root() {
        return root_;
    }
};
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */