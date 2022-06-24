class Solution {
public:
    // dp[i] = maximum sum after we make k partition of the array
    int solve(vector<int>&arr, int k, vector<int>&dp, int cur) {
        int n = arr.size();
        if(cur >= arr.size()) return 0;
        if(dp[cur] != -1) return dp[cur];
        // at each k we can partition the arry
        int maxNum = 0, sum = 0;
        for(int i=cur; i<min(n, cur+k); i++) {
            maxNum = max(maxNum, arr[i]);
            sum = max(sum , maxNum * (i - cur + 1) + solve(arr, k, dp, i+1));
        }
        return dp[cur] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return solve(arr, k, dp, 0);
    }
};