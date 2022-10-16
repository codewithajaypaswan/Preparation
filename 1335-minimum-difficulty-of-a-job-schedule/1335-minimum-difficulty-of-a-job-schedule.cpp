class Solution {
public:
    int findMax(vector<int>&jobs, int ind) {
        int ans = INT_MIN;
        for(int i=ind; i<jobs.size(); i++) {
            ans = max(ans, jobs[i]);
        }
        return ans;
    }
    int solve(vector<int>&jobs, int d, int ind, vector<vector<int>>&dp) {
        if(ind >= jobs.size()) return 0;
        if(d == 1) return findMax(jobs, ind);
        if(dp[ind][d] != -1) return dp[ind][d];
        int n = jobs.size() - d + 1, mn = -1e9, ans = 1e9;
        for(int i=ind; i<n; i++) {
            mn = max(mn, jobs[i]);
            ans = min(ans, mn + solve(jobs, d-1, i+1, dp));
        }
        return dp[ind][d] = ans;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if(n < d) return -1;
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        return solve(jobs, d, 0, dp);
    }
};