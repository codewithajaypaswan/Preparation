class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dfs(vector<vector<int>>&grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) return 0;
        int ans = 1;
        grid[x][y] = 0;
        for(int i=0; i<4; i++) {
            ans += dfs(grid, x+dx[i], y+dy[i]);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};