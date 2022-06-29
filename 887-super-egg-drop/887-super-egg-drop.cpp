class Solution {
public:
    int solve(int floor, int egg, vector<vector<int>>&dp) {
        if(floor == 1 || floor == 0) return floor;
        if(egg == 1) return floor;
        if(dp[floor][egg] != -1) return dp[floor][egg];
        int low = 1, high = floor, mn = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int eggBreak = solve(mid-1, egg-1, dp);
            int notBreak = solve(floor-mid, egg, dp);
            int temp = 1 + max(eggBreak, notBreak);
            if(eggBreak < notBreak) {
                low = mid+1; // go to more of wrost case
            }
            else {
                high = mid-1;
            }
            mn = min(mn, temp);
        }
        return dp[floor][egg] = mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
};