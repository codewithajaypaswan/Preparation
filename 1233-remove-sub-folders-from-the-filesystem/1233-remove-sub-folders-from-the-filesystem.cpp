class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
bool insert(TrieNode* root, string &s) {
    TrieNode* cur = root;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '/') continue;
        if(cur->children[s[i] - 'a'] == NULL) {
            cur->children[s[i] - 'a'] = new TrieNode();
        }
        cur = cur->children[s[i] - 'a'];
        if(i+1 < s.size() && s[i+1] == '/' && cur->isEnd) return false;
    }
    cur->isEnd = true;
    return true;
}
class Solution {
public:
    static bool cmp(string &A, string &B) {
        return A.size() < B.size();
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(), folder.end(), cmp);
        TrieNode* root = new TrieNode();
        for(string f:folder) {
            if(insert(root, f)) {
                ans.push_back(f);
            }
        }
        return ans;
    }
};