class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>>dp(n, vector<int>(2001, 0));
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int dif = nums[i] - nums[j] + 1000;
                if(dp[j][dif] + 1 > dp[i][dif]) {
                    dp[i][dif] = max(2, dp[j][dif] + 1);
                    ans = max(ans, dp[i][dif]);
                }
            }
        }
        return ans;
    }
};