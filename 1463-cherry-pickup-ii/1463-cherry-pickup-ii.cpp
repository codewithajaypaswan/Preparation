class Solution {
public:
    int dp[72][72][72];
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, m-1);
    }
    int solve(vector<vector<int>>&g, int r, int c1, int c2) {
        if(r == g.size() || c1 < 0 || c2 < 0 || c1 >= g[0].size() || c2 >= g[0].size()) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int move = g[r][c1], mx = 0;
        if(c1 != c2) move += g[r][c2];
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                mx = max(mx, solve(g, r+1, c1+i, c2+j));
            }
        }
        move += mx;
        return dp[r][c1][c2] = move;
    }
};