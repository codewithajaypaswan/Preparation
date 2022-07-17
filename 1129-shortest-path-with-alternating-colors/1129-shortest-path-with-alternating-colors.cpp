class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>adj[2][n+1];
        for(auto r:redEdges) {
            adj[0][r[0]].push_back(r[1]);
        }
        for(auto b:blueEdges) {
            adj[1][b[0]].push_back(b[1]);
        }
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        dp[0][0] = dp[0][1] = 0;
        queue<pair<int,int>>q;
        q.push({0, 0});
        q.push({0, 1});
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            int u = it.first, type = it.second;
            for(auto v:adj[1-type][u]) {
                if(dp[v][1-type] == -1) {
                    dp[v][1-type] = dp[u][type] + 1;
                    q.push({v, 1-type});
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++) {
            if(dp[i][0] != -1 && dp[i][1] != -1) {
                ans.push_back(min(dp[i][0], dp[i][1]));
            }
            else if(dp[i][0] != -1) {
                ans.push_back(dp[i][0]);
            }
            else if(dp[i][1] != -1) {
                ans.push_back(dp[i][1]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};