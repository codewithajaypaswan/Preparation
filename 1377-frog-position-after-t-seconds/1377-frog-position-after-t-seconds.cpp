class Solution {
public:
    double bfs(vector<int>adj[], int time, int target, vector<int>&vis) {
        queue<pair<int, pair<int, double>>>q;
        q.push({1, {0, 1.0}}); // {root, time, probability}
        vis[1] = true;
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            int cur = it.first, t = it.second.first;
            double prob = it.second.second;
            // cout<<cur<<" "<<prob<<endl;
            int cnt = 0;
            for(auto child:adj[cur]) {
                if(!vis[child]) cnt++;
            }
            if(cur == target) {
                if(t == time || ((t < time) and cnt == 0)) return prob;
                return 0.0;
            }
            for(auto child:adj[cur]) {
                if(vis[child]) continue;
                // cout<<child<<" "<<prob<<" "<<adj[cur].size()<<endl;
                q.push({child, {t + 1, (1.0/cnt) * prob}});
                vis[child] = true;
            }
        }
        return 0.0;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int>adj[n+1];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n+1, 0);
        return bfs(adj, t, target, vis);
    }
};