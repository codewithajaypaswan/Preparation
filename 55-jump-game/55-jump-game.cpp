class Solution {
public:
    bool solve(vector<int>&nums, vector<int>&dp, int cur) {
        if(cur >= nums.size()-1) return true;
        if(dp[cur] != -1) return dp[cur];
        int n = nums.size(), ans = 0;
        for(int i=cur; i<min(n, cur + nums[cur]); i++) {
            ans |= solve(nums, dp, i+1);
            if(ans) return dp[cur] = ans;
        }
        return dp[cur] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(nums, dp, 0);
    }
};