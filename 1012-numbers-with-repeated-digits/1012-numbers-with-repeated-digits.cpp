class Solution {
public:
    int dp[11][1024][2][2];
    int solve(string &s, int pos, int mask, int bound, int repeated) {
        if(pos == s.size()) {
            if(repeated) {
                return 1;
            }
            return 0;
        }
        if(dp[pos][mask][bound][repeated] != -1) return dp[pos][mask][bound][repeated];
        int maxDigit = bound ? s[pos] - '0' : 9;
        int ans = 0;
        for(int i=0; i<=maxDigit; i++) {
            if(i == 0 && mask == 0) ans += solve(s, pos+1, mask, bound & (i == s[pos] - '0'), false);
            else if(mask & (1<<i)) ans += solve(s, pos+1, mask, bound&(i==s[pos] - '0'), true);
            else ans += solve(s, pos+1, mask^(1<<i), bound&(i == s[pos] - '0'), repeated);
        }
        return dp[pos][mask][bound][repeated] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0, 1, 0);
    }
};