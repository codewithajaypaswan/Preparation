class Solution {
public:
    int mod = 1e9+7;
    int solve(string &s, int cur, int k, vector<vector<int>>&dp) {
        if(cur >= s.size()) return k == 2;
        if(dp[cur][k] != -1) return dp[cur][k];
        long ans = 0;
        if(k == 2) {
            if(s[cur] == 'P')  {
                ans = (ans + solve(s, cur+1, 0, dp) + solve(s, cur+1, k, dp))%mod;
            }
            else {
                ans = (ans + solve(s, cur+1, 1, dp))%mod;
            }
        }
        else {
            ans = (ans + solve(s, cur+1, k + (s[cur] == 'S'), dp))%mod;
        }
        return dp[cur][k] = ans;
    }
    int numberOfWays(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return solve(s, 0, 0, dp);
    }
};