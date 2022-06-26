class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<int>&color, int cur, int c) {
        if(color[cur] != 0) return color[cur] == c;
        color[cur] = c;
        for(int x:graph[cur]) {
            if(!dfs(graph, color, x, -c)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, 0);
        for(int i=0; i<n; i++) {
            if(color[i] == 0) {
                if(!dfs(graph, color, i, 1)) return false; 
            }
        }
        return true;
    }
};