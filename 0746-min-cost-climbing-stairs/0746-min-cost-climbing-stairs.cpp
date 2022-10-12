class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1), dp1(n, -1);
        return min(solve(cost, dp, 0), solve(cost, dp1, 1));
    }
    int solve(vector<int>&cost, vector<int>&dp, int cur) {
        if(cur >= cost.size()) return 0;
        if(dp[cur] != -1) return dp[cur];
        return dp[cur] = min(cost[cur] + solve(cost, dp, cur+1), cost[cur] + solve(cost, dp, cur+2));
    }
};