class TrieNode {
public:
    bool isEnd;
    TrieNode* child[26];
    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            child[i] = NULL;
        }
    }
};

void addTrie(vector<string>&words, TrieNode* root) {
    for(string s:words) {
        TrieNode* pCrawl = root;
        for(char c:s) {
            if(pCrawl->child[c - 'a'] == NULL)
                pCrawl->child[c - 'a'] = new TrieNode();
            pCrawl = pCrawl->child[c - 'a'];
        }
        pCrawl->isEnd = true;
    }
}
  


class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<string>ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        addTrie(words, root);
        
        unordered_set<string>result;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                TrieNode* temp = root;
                dfs(board, i, j, temp, result, "");
            }
        }
        for(auto s:result) ans.push_back(s);
        return ans;
    }
    void dfs(vector<vector<char>>&board, int x, int y, TrieNode* root, unordered_set<string>&result, string w) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;
        if(root->child[board[x][y] - 'a'] == NULL) return;
        w += board[x][y];
        root = root->child[board[x][y] - 'a'];
        if(root->isEnd) result.insert(w);
        char ch = board[x][y];
        board[x][y] = ' ';
        for(int i=0; i<4; i++) {
            dfs(board, x+dx[i], y+dy[i], root, result, w);
        }
        board[x][y] = ch;
        
        
    }
};