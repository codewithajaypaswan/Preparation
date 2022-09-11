class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<int>parent(n, -1);
        vector<int>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto e:edges) {
            int u = find(e[0], parent);
            int v = find(e[1], parent);
            if(u == v) continue;
            parent[u] = v;
        }
        return find(source, parent) == find(destination, parent);
    }
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
    }
};