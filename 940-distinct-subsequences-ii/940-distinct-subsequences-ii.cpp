class Solution {
public:
    int distinctSubseqII(string s) {
        long n = s.size(), mod = 1e9+7, ans = 0;
        vector<long>dp(n+1, 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(s[i] != s[j]) {
                    dp[i] = (dp[i] + dp[j])%mod;
                }
            }
            ans = (dp[i] + ans)%mod;
        }
        return ans;
    }
};