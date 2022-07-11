class Solution {
public:
    int solve(vector<int>&cuts, int i, int j, vector<vector<int>>&dp) {
        if(i > j) return 0;
        int ans = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i; k<=j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + solve(cuts, i, k-1, dp) + solve(cuts, k+1, j, dp);
            ans = min(cost, ans);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(size+2, vector<int>(size+2, -1));
        return solve(cuts, 1, size, dp);
    }
};