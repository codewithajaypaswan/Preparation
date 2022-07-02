/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string ans;
    void serialize_tree(TreeNode* root) {
        if(!root) return;
        ans += to_string(root->val) + " ";
        serialize_tree(root->left);
        serialize_tree(root->right);
    }
    string serialize(TreeNode* root) {
        serialize_tree(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int>q;
        istringstream iss(data);
        string s;
        while(iss >> s) q.push(stoi(s));
        return deserialize_tree(q, INT_MIN, INT_MAX);
    }
    TreeNode* deserialize_tree(queue<int>&q, int low, int high) {
        if(q.empty()) return NULL;
        int cur = q.front();
        if(cur < low || cur > high) return NULL;
        q.pop();
        TreeNode* root = new TreeNode(cur);
        root->left = deserialize_tree(q, low, cur);
        root->right = deserialize_tree(q, cur, high);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;