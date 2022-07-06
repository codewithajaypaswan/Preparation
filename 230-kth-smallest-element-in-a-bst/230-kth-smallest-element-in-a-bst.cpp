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
class TreeWithCount {
public:
    int count, val;
    TreeWithCount* left, *right;
    TreeWithCount(int x) {
        val = x;
        count = 1;
        left = right = NULL;
    }
};


class Solution {
public:
    int n = 1;
    
    TreeWithCount* build(TreeNode* root) {
        if(!root) return NULL;
        TreeWithCount* cur = new TreeWithCount(root->val);
        cur->left = build(root->left);
        cur->count = n++;
        cur->right = build(root->right);
        return cur;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeWithCount * cur = build(root);
        while(cur) {
            if(cur->count == k) return cur->val;
            else if(cur->count > k) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return -1;
    }
};