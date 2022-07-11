class Solution {
public:
    int solve(vector<int>&arr, int k, int cur, vector<int>&dp) {
        if(cur >= arr.size()) return 0;
        int ans = 0, n = arr.size(), mx = 0;
        if(dp[cur] != -1) return dp[cur];
        for(int i=cur; i<min(n, cur+k); i++) {
            mx = max(mx, arr[i]);
            ans = max(ans, mx * (i - cur + 1) + solve(arr, k, i+1, dp));
        }
        return dp[cur] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return solve(arr, k, 0, dp);
    }
};