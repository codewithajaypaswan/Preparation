class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums) sum += x;
        if(sum&1) return false;
        int n = nums.size(), target = sum/2;
        vector<vector<int>>dp(n+1, vector<int>(sum/2+1, 0));
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum/2; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = 0LL + dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum/2];
    }
    bool solve(vector<int>&nums, vector<vector<int>>&dp, int cur, int target) {
        if(target == 0) return true;
        if(cur >= nums.size() || target < 0) return false;
        if(dp[cur][target] != -1) return dp[cur][target];
        return dp[cur][target] = solve(nums, dp, cur+1, target - nums[cur]) || solve(nums, dp, cur+1, target);
    }
};