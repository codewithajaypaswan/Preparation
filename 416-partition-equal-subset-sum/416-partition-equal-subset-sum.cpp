class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums) sum += x;
        if(sum&1) return false;
        int n = nums.size(), target = sum/2;
        vector<vector<int>>dp(n+1, vector<int>(sum/2+1, -1));
        return solve(nums, dp, 0, target);
    }
    bool solve(vector<int>&nums, vector<vector<int>>&dp, int cur, int target) {
        if(target == 0) return true;
        if(cur >= nums.size() || target < 0) return false;
        if(dp[cur][target] != -1) return dp[cur][target];
        return dp[cur][target] = solve(nums, dp, cur+1, target - nums[cur]) || solve(nums, dp, cur+1, target);
    }
};