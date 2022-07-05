class Solution {
public:
    int solve(vector<int>&nums, vector<int>&dp, int cur) {
        if(cur >= nums.size()-1) return 0;
        if(dp[cur] != -1) return dp[cur];
        int ans = 1e9;
        for(int i=1; i<=min(nums[cur], (int)nums.size()-1); i++) {
            ans = min(ans, 1 + solve(nums, dp, cur+i));
        }
        return dp[cur] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(nums, dp, 0);
    }
};