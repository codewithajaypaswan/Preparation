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
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int>ans;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()) {
            Node* cur = st.top(); st.pop();
            for(Node* child:cur->children) {
                st.push(child);
            }
            ans.push_back(cur->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};