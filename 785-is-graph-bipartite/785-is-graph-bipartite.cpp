class Solution {
public:
    bool dfs(vector<vector<int>>&graph, int cur, int c, vector<int>&color) {
        if(color[cur] != 0) return color[cur] == c;
        color[cur] = c;
        for(int child:graph[cur]) {
            if(!dfs(graph, child, -c, color)) return false; 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, 0);
        for(int i=0; i<n; i++) {
            if(color[i] == 0) {
                if(!dfs(graph, i, 1, color)) return false;
            }
        }
        return true;
    }
};