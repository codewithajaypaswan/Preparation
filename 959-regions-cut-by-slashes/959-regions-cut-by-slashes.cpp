class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>&g, int x, int y) {
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y]) return ;
        g[x][y] = 1;
        for(int i=0; i<4; i++) {
            dfs(g, x+dx[i], y+dy[i]);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>g(n*3, vector<int>(n*3, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '/') g[i*3+2][j*3] = g[i*3+1][j*3+1] = g[i*3][j*3+2] = 1;
                else if(grid[i][j] == '\\') g[i*3][j*3] = g[i*3+1][j*3+1] = g[i*3+2][j*3+2] = 1;
            }
        }
        int count = 0;
        for(int i=0; i<g.size(); i++) {
            for(int j=0; j<g.size(); j++) {
                if(g[i][j] == 0) {
                    dfs(g, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};