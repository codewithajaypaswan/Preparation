class Solution {
public:
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp) {
        if(i >= j) return 0;
        int tempAns = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i; k<j; k++) {
            tempAns = max(tempAns, solve(i, k, nums, dp) + solve(k+1, j, nums, dp) + nums[i-1] * nums[k] * nums[j]);
        }
        return dp[i][j] = tempAns;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1 );
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(1, n-1, nums, dp);
    }
};