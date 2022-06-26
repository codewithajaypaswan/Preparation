class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto t:times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<int>dist(n+1, 1e9), vis(n+1, 0);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, k});
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int u = it.second;
            vis[u] = 1;
            for(auto[v,wt]:adj[u]) {
                if(vis[v] == 0 && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = max(ans, dist[i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};