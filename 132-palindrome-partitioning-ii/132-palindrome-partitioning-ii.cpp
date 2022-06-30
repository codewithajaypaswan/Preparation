class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n);
        for(int i=0; i<n; i++) dp[i] = i;
        for(int i=0; i<n; i++) {
            // for odd length
            for(int start = i, end = i; start >= 0 && end < n && s[start] == s[end]; start--, end++) {
                int newCut = start == 0 ? 0 : dp[start-1] + 1;
                dp[end] = min(dp[end], newCut);
            }
            // for even length
            for(int start = i-1, end = i; start >= 0 && end < n && s[start] == s[end]; start--, end++) {
                int newCut = start == 0 ? 0 : dp[start-1] + 1;
                dp[end] = min(dp[end], newCut);
            }
        }
        return dp[n-1];
    }
};