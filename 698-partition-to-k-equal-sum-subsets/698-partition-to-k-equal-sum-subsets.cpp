class Solution {
public:
    //1, first approack is backtracking
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long sum = 0, n = nums.size();
        for(int x:nums) sum += x;
        if(sum%k != 0 || k == 0) return false;
        int target = sum/k;
        vector<int>dp((1<<n), -1);
        dp[0] = 0;
        for(int mask=0; mask < (1<<n); mask++) {
            if(dp[mask] == -1) continue;
            for(int i=0; i<n; i++) {
                if(!(mask & (1<<i)) && dp[mask] + nums[i] <= target) {
                    dp[mask | (1<<i)] = (dp[mask] + nums[i])%target;
                }
            }
        } 
        // 1111
        return dp[(1<<n) - 1] == 0;
    }
};