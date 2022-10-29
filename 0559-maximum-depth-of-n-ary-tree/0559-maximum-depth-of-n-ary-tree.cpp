/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = 0;
    void dfs(Node* root, int depth) {
        if(!root) return;
        if(root->children.size() == 0) {
            ans = max(ans, depth);
        }
        for(Node* child:root->children) {
            dfs(child, depth+1);
        }
    }
    int maxDepth(Node* root) {
        dfs(root, 1);
        return ans;
    }
};