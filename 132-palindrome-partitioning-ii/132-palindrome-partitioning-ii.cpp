class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1);
        for(int i=0; i<=n; i++) dp[i] = i-1;
        for(int i=0; i<n; i++) {
            for(int j=0; i-j >= 0 && j+i < n && s[i-j] == s[j+i]; j++) {
                dp[i+j+1] = min(dp[i+j+1], dp[i-j] + 1);
            }
            for(int j=1; i-j+1 >= 0 && j+i < n && s[i-j+1] == s[j+i]; j++) {
                dp[i+j+1] = min(dp[i+j+1], dp[i-j+1] + 1);
            }
        }
        return dp[n];
    }
};