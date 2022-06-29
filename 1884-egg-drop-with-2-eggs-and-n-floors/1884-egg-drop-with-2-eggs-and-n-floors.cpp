class Solution {
public:
    int solve(int floor, int egg, vector<vector<int>>&dp) {
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;
        if(dp[floor][egg] != -1) return dp[floor][egg];
        int mn = INT_MAX;
        for(int i=1; i<=floor; i++) {
            int temp = 1 + max(solve(i-1, egg-1, dp), solve(floor - i, egg, dp));
            mn = min(mn, temp);
        }
        return dp[floor][egg] = mn;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return solve(n, 2, dp);
    }
};