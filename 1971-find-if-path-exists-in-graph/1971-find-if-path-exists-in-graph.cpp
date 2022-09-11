class Solution {
public:
    void dfs(vector<int>adj[], vector<int>&vis, int &src, int &dest, int source, int destination, int cur) {
        if(vis[cur]) return;
        vis[cur] = 1;
        if(cur == source) src = 1;
        if(cur == destination) dest = 1;
        for(int x:adj[cur]) {
            dfs(adj, vis, src, dest, source, destination, x);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++) {
            
            if(vis[i] == 0) {
                int src = 0, dest = 0;
                dfs(adj, vis, src, dest, source, destination, i);
                if(src == 1 && dest == 1) return true;
                if(src == 1 || dest || 1) return false;
            }
        }
        return false;
    }
};