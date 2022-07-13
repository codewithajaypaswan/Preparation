class Solution {
public:
    //1, first approack is backtracking
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int x:nums) sum += x;
        if(k == 0 || sum%k != 0) return false;
        vector<int>dp((1<<n), -1);
        return solve(nums, dp, sum/k, k);
    }
    bool solve(vector<int>&nums, vector<int>&dp, int target, int k) {
        int n = nums.size();
        dp[0] = 0;
        for(int mask = 0; mask < (1<<n); mask++) {
            if(dp[mask] == -1) continue;
            for(int i=0; i < n; i++) {
                if(!(mask&(1<<i)) && dp[mask] + nums[i] <= target)
                dp[mask|(1<<i)] = (dp[mask] + nums[i])%target;
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};