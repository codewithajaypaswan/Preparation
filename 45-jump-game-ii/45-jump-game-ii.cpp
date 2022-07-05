class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1e9);
        dp[0] = 0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] + j >= i) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                    break;
                }
            }
        }
        return dp[n-1];
    }
};