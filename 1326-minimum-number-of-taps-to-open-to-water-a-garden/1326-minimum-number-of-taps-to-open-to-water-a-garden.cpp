class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;
        for(int i=0; i<=n; i++) {
            int start = max(0, i+-ranges[i]);
            int end = min(n, i+ranges[i]);
            for(int j=start+1; j<=end; j++) {
                dp[j] = min(dp[j], 1 + dp[start]);
            }
        }
        return dp[n] == 1e9 ? -1 : dp[n];
    }
};