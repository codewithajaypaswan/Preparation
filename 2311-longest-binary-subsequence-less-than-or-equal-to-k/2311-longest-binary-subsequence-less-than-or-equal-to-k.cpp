class Solution {
public:
    int solve(string &s, int k, vector<vector<int>>&dp, int cnt, int ind) {
        if(ind >= s.size()) return 0;
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        if(s[ind] == '0') {
            return dp[ind][cnt] = max(1 + solve(s, k, dp, cnt+1, ind+1), solve(s, k, dp, cnt, ind+1));
        }
        else {
            int temp = 0;
            if(cnt < 31 && k - (1<<cnt) >= 0) 
                temp = max(temp, 1 + solve(s, k - (1<<cnt), dp, cnt+1, ind+1));
            return dp[ind][cnt] = max(temp, solve(s, k, dp, cnt, ind+1));
        }
        return dp[ind][cnt];
    }
    int longestSubsequence(string s, int k) {
        int n = s.size();
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(s, k, dp, 0, 0);
    }
};