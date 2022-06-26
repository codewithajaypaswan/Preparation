class Solution {
public:
    int dfs(vector<int>&arr, int k, vector<int>&dp, int cur) {
        if(cur >= arr.size()) return 0;
        if(dp[cur] != -1) return dp[cur];
        int maxNum = 0, sum = 0;
        for(int i=cur; i<min((int)arr.size(), cur + k); i++) {
            int len = i - cur + 1;
            maxNum = max(maxNum, arr[i]);
            sum = max(sum, maxNum * len + dfs(arr, k, dp, i+1));
        }
        return dp[cur] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return dfs(arr, k, dp, 0);
    }
};