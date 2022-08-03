class Solution {
public:
    int ans = INT_MIN;
    void dfs(vector<int>&edges, vector<int>&vis, int cur, vector<int>&dist, int len) {
        if(cur == -1) return;
        if(vis[cur] == 0) {
            vis[cur] = 1;
            dist[cur] = len;
            dfs(edges, vis, edges[cur], dist, len + 1);
            dist[cur] = -1;
        }
        else {
            if(dist[cur] != -1) ans = max(ans, len - dist[cur]);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n, 0), dist(n, -1);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(edges, vis, i, dist, 0);
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};