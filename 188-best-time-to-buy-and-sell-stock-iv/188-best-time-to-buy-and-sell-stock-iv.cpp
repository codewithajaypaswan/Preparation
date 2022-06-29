class Solution {
public:
    int solve(int k, vector<int>&prices, int cur, vector<vector<int>>&dp) {
        if(cur >= prices.size() || k == 0) return 0;
        int ans = 0;
        if(dp[cur][k] != -1) return dp[cur][k];
        // we have two choices either we buy at this day or skip this day
        // 1. buy
        // if i buy at ith day then we can sell at i+1 th day, then profit will be prices[cur] - prices[i]
        // else we can skip
        for(int i=cur; i<prices.size(); i++) {
            if(prices[i] - prices[cur] > 0)
                ans = max(ans, prices[i] - prices[cur] + solve(k-1, prices, i+1, dp));
        }
        ans = max(ans, solve(k, prices, cur+1, dp));
        return dp[cur][k] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(k, prices, 0, dp);
    }
};