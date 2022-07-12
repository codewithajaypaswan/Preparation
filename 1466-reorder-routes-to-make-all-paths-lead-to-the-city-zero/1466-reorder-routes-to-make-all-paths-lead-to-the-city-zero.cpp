class Solution {
public:
    int cnt = 0;
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(-e[0]);
        }
        dfs(adj, 0, -1);
        return cnt;
    }
    void dfs(vector<int>adj[], int cur, int parent) {
        for(auto child:adj[cur]) {
            if(abs(child) == parent) continue;
            if(child > 0) cnt++;
            dfs(adj, abs(child), cur);
        }
    }
};