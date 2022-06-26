class Solution {
public:
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1, -1);
        for(auto e:edges) {
            int u = find(e[0], parent);
            int v = find(e[1], parent);
            if(u == v) return {e[0], e[1]};
            parent[u] = v;
        }
        return {};
    }
};