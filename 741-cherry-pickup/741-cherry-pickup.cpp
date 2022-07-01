class Solution {
public:
    int dp[51][51][51][51];
    int solve(vector<vector<int>>&g, int n, int r1, int c1, int r2, int c2) {
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || g[r1][c1] == -1 || g[r2][c2] == -1) return -1e9;
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        if(r1 == n-1 && c1 == n-1) return g[r1][c1];
        int cherry = g[r1][c1];
        if(r1 != r2) {
            cherry += g[r2][c2];
        }
        int rr = solve(g, n, r1, c1+1, r2, c2+1);
        int dd = solve(g, n, r1+1, c1, r2+1, c2);
        int rd = solve(g, n, r1, c1+1, r2 + 1, c2);
        int dr = solve(g, n, r1+1, c1, r2, c2+1);
        int temp = max({rr, rd, dd, dr});
        cherry += temp;
        return dp[r1][c1][r2][c2] = cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(grid, n, 0, 0, 0, 0));
    }
};