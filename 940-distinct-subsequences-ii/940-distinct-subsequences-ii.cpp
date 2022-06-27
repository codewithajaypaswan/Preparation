class Solution {
public:
    int distinctSubseqII(string s) {
        long n = s.size(), mod = 1e9+7, ans = 0, added = 0;
        vector<long>endWith(26, -1);
        vector<long>dp(n+1);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            dp[i] = (dp[i-1]*2)%mod; // concatening the character at the end
            if(endWith[s[i-1]-'a'] >= 0) {
                dp[i] = (dp[i] - dp[endWith[s[i-1]-'a']]+mod)%mod;
            }
            endWith[s[i-1] - 'a'] = i-1;
        }
        // remove the non empty subsequcence
        return (dp[n]-1)%mod;
    }
};