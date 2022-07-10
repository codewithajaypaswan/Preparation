class Solution {
public:
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
    }
    bool _union(int u, int v, vector<int>&parent) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(pu == pv) return false;
        parent[pv] = pu;
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>parent(n+1, -1);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    if(_union(i, j, parent)) cnt++;
                }
            }
        }
        return cnt;
    }
};