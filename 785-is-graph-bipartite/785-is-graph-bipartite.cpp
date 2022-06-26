class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, 0);
        for(int i=0; i<n; i++) {
            if(color[i]) continue;
            color[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int adj:graph[cur]) {
                    if(color[adj] == 0) {
                        color[adj] = -color[cur];
                        q.push(adj);
                    }
                    else {
                        if(color[adj] != -color[cur]) return false;
                    }
                }
            }
        }
        return true;
    }
};