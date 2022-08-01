class Solution {
public:
    int solve(int n, int m, int x, int y, vector<vector<int>>&dp) {
        if(x == n && y == m) return 1;
        if(x > n || y > m) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = solve(n, m, x+1, y, dp) + solve(n, m, x, y+1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, 0, 0, dp);
    }
};