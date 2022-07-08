class TrieNode {
public:
    vector<string>db;
    TrieNode* children[26];
    TrieNode() {
        for(int i=0; i<26; i++) children[i] = NULL;
        db.clear();
    }
};
void insert(string &s, TrieNode* root) {
    TrieNode* cur = root;
    for(int i=0; i<s.size(); i++) {
        if(cur->children[s[i] - 'a'] == NULL) {
            cur->children[s[i] - 'a'] = new TrieNode();
        }
        cur = cur->children[s[i] - 'a'];

        if(cur->db.size() < 3) cur->db.push_back(s);
    }
}
    
vector<string> search(string &s, TrieNode* root) {
    TrieNode* cur = root;
    for(int i=0; i<s.size(); i++) {
        if(cur->children[s[i] - 'a'] == NULL) return {};
        cur = cur->children[s[i] - 'a'];
    }
    if(cur == NULL) return {};
    return cur->db;

}
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        for(int i=0; i<products.size(); i++) {
            insert(products[i], root);
        }
        vector<vector<string>>ans;
        string cur = "";
        for(int i=0; i<searchWord.size(); i++) {
            cur += searchWord[i];
            ans.push_back(search(cur, root));
        }
        return ans;
    }
};