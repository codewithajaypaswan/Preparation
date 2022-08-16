class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

string ans;

void insert(TrieNode* root, string &s) {
    TrieNode* cur = root;
    string prefix = "";
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        if(cur->children[c - 'a'] == NULL) {
            if(i != s.size()-1) return;
            cur->children[c - 'a'] = new TrieNode();
            prefix += c;
        }
        else {
            cur = cur->children[c - 'a'];
            prefix += c;
        }
    }
    if(ans.size() < prefix.size() || (ans.size() == prefix.size() && ans > prefix)) {
        ans = prefix;
    }
}
// static bool cmp(string &)
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        ans = "";
        TrieNode* root = new TrieNode();
        for(string s:words) {
            insert(root, s);
        }
        return ans;
    }
};