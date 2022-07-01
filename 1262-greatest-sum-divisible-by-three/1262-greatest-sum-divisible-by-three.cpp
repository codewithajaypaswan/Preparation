class Solution {
public:
    int solve(vector<int>&nums, int ind,vector<vector<int>>&dp, int rem = 0) {
        if(ind >= nums.size()) return rem == 0 ? 0 : -1e9;
        if(dp[ind][rem] != -1) return dp[ind][rem];
        int case1 = nums[ind] + solve(nums, ind+1, dp, (rem + nums[ind])%3);
        int case2 = solve(nums, ind+1, dp, rem%3);
        return dp[ind][rem] = max(case1, case2);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(4, -1));
        return solve(nums, 0, dp);
    }
};