class TrieNode{
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* cur = root;
        for(int i=31; i>=0; i--) {
            int bit = (num>>i)&1;
            if(cur->child[bit] == NULL) {
                cur->child[bit] = new TrieNode();
            }
            cur = cur->child[bit];
        }
    }
    
    int maxXor(int num) {
        TrieNode* cur = root;
        int ans = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num>>i)&1;
            if(cur->child[!bit]) {
                ans += (1<<i);
                cur = cur->child[!bit];
            }
            else {
                cur = cur->child[bit];
            }
        }
        return ans;
    }
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        for(int i=0; i<nums.size(); i++) {
            root->insert(nums[i]);
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = max(ans, root->maxXor(nums[i]));
        }
        return ans;
    }
};