class Solution {
public:
    bool dfs(vector<int>adj[], vector<int>&color, int cur, int parent, int c) {
        if(color[cur] != 0) return color[cur] == c;
        color[cur] = c;
        for(auto child:adj[cur]) {
            if(child == parent) continue;
            if(!dfs(adj, color, child, cur, -c)) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto d:dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        vector<int>color(n+1, 0);
        for(int i=1; i<=n; i++) {
            if(color[i] != 0) continue;
            color[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()) {
                int i = q.front(); q.pop();
                for(int j:adj[i]) {
                    if(!color[j]) {
                        color[j] = - color[i];
                        q.push(j);
                    }
                    else if(color[j] != -color[i]) return false;
                }
            }
        }
        return true;
    }
};