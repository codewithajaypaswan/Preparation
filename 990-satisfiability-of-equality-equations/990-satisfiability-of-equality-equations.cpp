class Solution {
public:
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
    }
    bool equationsPossible(vector<string>& equ) {
        vector<int>parent(26, -1), rank(26, 1);
        for(string s:equ) {
            int u = s[0] - 'a', v = s[3] - 'a';
            if(s[1] == '!') continue;
            int pu = find(u, parent);
            int pv = find(v, parent);
            if(pu == pv) continue;
            if(rank[pv] > rank[pu]) {
                parent[pu] = pv;
                rank[pv] += rank[pu];
            }
            else {
                parent[pv] = pu;
                rank[pu] += rank[pv];
            }
        }
        for(string s:equ) {
            int u = s[0] - 'a', v = s[3] - 'a';
            if(s[1] == '!') {
                if(find(u, parent) == find(v, parent)) return false;
            }
        } 
        return true;
    }
};