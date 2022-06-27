class Solution {
public:
    int mod = 1e9+7;
    int dp[505][505];
    int solve(int cur, int steps, int arrLen) {
        if(cur == 0 && steps == 0) return 1;
        if(cur < 0 || cur >= arrLen || steps == 0 || cur > steps) return 0;
        if(dp[cur][steps] != -1) return dp[cur][steps];
        return dp[cur][steps] = (0LL + solve(cur+1, steps-1, arrLen) + solve(cur, steps-1, arrLen) + solve(cur-1, steps-1, arrLen))%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return solve(0, steps, arrLen);
    }
};