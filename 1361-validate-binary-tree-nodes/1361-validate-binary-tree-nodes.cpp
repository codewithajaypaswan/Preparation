class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int>adj[n];
        vector<int>in(n, 0), out(n, 0);
        for(int i=0; i<n; i++) {
            if(l[i] != -1) {
                adj[i].push_back(l[i]);
                out[i]++;
                in[l[i]]++;
            }
            if(r[i] != -1) {
                adj[i].push_back(r[i]);
                out[i]++;
                in[r[i]]++;
            }
        }
        
        // check if only 1 root is there for a tree
        int rootCount = 0, root = -1;
        for(int i=0; i<n; i++) {
            if(in[i] == 0 && out[i] <= 2) {
                root = i;
                rootCount++;
            }
        }
        if(rootCount != 1) return false;
        
        // check if every node as exactly one parent
        for(int i=0; i<n; i++) {
            if(in[i] != 1 && i != root) return false; 
        }
        
        // check for cycle
        vector<int>vis(n+1, 0);
        // for(int i=0; i<n; i++) {
        //     if(vis[i] == 0) {
                if(dfs(vis, adj, root, -1)) return false;
        //     }
        // }
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) return false;
        }
        return true;
    }
    bool dfs(vector<int>&vis, vector<int>adj[], int cur, int parent) {
        if(vis[cur] == 2) return true;
        if(vis[cur] == 1) return false;
        vis[cur] = 2;
        for(int x:adj[cur]) {
            if(x == parent) continue;
            if(dfs(vis, adj, x, cur)) return false;
        }
        vis[cur] = 1;
        return false;
    }
};