class Solution {
public:
    int findMax(vector<int>&jobs, int ind) {
        int mx = INT_MIN;
        for(int i=ind; i<jobs.size(); i++) {
            mx = max(mx, jobs[i]);
        }
        return mx;
    }
    int solve(vector<int>&jobs, int d, int ind, vector<vector<int>>&dp) {
        if(ind >= jobs.size()) return 0;
        if(d == 1) return findMax(jobs, ind);
        if(dp[ind][d] != -1) return dp[ind][d];
        int mx = -1e9, ans = 1e9;
        for(int i=ind; i<jobs.size()-d+1; i++) {
            mx = max(mx, jobs[i]);
            ans = min(ans, mx + solve(jobs, d-1, i+1, dp));
        }
        return dp[ind][d] = ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(n < d) return -1;
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        return solve(job, d, 0, dp);
    }
};