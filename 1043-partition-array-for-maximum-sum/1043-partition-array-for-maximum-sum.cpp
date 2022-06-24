class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, 0);
        for(int i=1; i<=n; i++) {
            int curMax = arr[i-1], best = dp[i-1];
            for(int j=1; i-j >= 0 && j <= k; j++) {
                curMax = max(curMax, arr[i-j]);
                best = max(best, curMax * j + dp[i-j]);
            }
            dp[i] = best;
        }
        return dp[n];
    }
};