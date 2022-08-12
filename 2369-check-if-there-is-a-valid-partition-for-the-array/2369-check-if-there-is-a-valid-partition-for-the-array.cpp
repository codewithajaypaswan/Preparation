class Solution {
public:
    int solve(vector<int>&nums, vector<int>&dp, int cur) {
        if(cur >= nums.size()) return true;
        if(dp[cur] != -1) return dp[cur];
        if(cur+1 < nums.size() && nums[cur] == nums[cur+1]) {
            if(solve(nums, dp, cur+2)) return dp[cur] = true;
            if(cur+2 < nums.size() && nums[cur] == nums[cur+2]) {
                if(solve(nums, dp, cur+3)) return dp[cur] = true;
            }
        }
        if(cur+2 < nums.size() && nums[cur+1] - nums[cur] == 1 && nums[cur+2] - nums[cur+1] == 1) {
            if(solve(nums, dp, cur+3)) return dp[cur] = true;
        }
        return dp[cur] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(nums, dp, 0);
    }
};