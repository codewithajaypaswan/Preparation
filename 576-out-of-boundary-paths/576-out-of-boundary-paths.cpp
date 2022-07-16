class Solution {
public:
    int dp[51][51][51];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int mod = 1e9+7;
    int dfs(int m, int n, int maxMove, int r, int c, int move) {
        if(r < 0 || r >= m || c < 0 || c >= n) return 1;
        if(move == maxMove) return 0;
        if(dp[r][c][move] != -1) return dp[r][c][move];
        long ans = 0;
        for(int i=0; i<4; i++) {
            ans = (ans + dfs(m, n, maxMove, r+dx[i], c+dy[i], move+1))%mod;
        }
        return dp[r][c][move] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn, 0);
    }
};