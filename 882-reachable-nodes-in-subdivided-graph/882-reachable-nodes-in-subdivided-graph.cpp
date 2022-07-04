class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<bool>vis(n, false);
        vector<vector<int>>g(n, vector<int>(n, -1));
        for(auto e:edges) {
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
        }
        priority_queue<pair<int,int>>pq;
        pq.push({maxMoves, 0});
        int ans = 0;
        while(!pq.empty()) {
            auto[move, cur] = pq.top(); pq.pop();
            if(vis[cur]) continue;
            vis[cur] = true;
            ans++;
            for(int i=0; i<n; i++) {
                if(g[cur][i] == -1) continue;
                if(!vis[i]  && move >= g[cur][i] + 1) {
                    pq.push({move - g[cur][i] - 1, i});
                }
                int moveCount = min(move, g[cur][i]);
                ans += moveCount;
                g[cur][i] -= moveCount;
                g[i][cur] -= moveCount;
            }
        }
        return ans;
    }
};