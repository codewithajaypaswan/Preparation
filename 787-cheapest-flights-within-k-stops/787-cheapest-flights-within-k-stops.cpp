class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dp(k+2, vector<int>(n+1, 1e9));
        for(int i=0; i<=k+1; i++) {
            dp[i][src] = 0;
        }
        for(int i=1; i<=k+1; i++) {
            for(auto f:flights) {
                int u = f[0], v = f[1], wt = f[2];
                if(dp[i-1][u] != 1e9) 
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + wt);
            }
        }
        return dp[k+1][dst] == 1e9 ? -1 : dp[k+1][dst];
    }
};