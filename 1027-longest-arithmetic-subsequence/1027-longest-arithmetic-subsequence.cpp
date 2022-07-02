class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2001,0));
        // dp[n][diff] : n=length of longest arr with 0 based indexing
        //              : diff is len of longest arr with differnce of diff
        //              : conclusion is dp[n][diff] tells us about the longest array with with the differnce of diff
        int ans = 2;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int dif = nums[i] - nums[j] + 1000;
                if(dp[j][dif] + 1 > dp[i][dif]) {
                    dp[i][dif] = max(2, 1 + dp[j][dif]);
                    ans = max(ans, dp[i][dif]);
                }
            }
        }
        return ans;
    }
};