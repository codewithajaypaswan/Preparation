class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, 0);
        for(int i=0; i<n; i++) {
            if(color[i] != 0) continue;
            queue<int>q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(auto child:graph[cur]) {
                    if(color[child] == 0) {
                        color[child] = -color[cur];
                        q.push(child);
                    }
                    else if(color[child] != -color[cur]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};