class Solution {
public:
    int dp[32][2][2];
    vector<int>v;
    int solve(int pos, int small, int prev) {
        if(pos >= v.size()) return 1;
        if(dp[pos][small][prev] != -1) return dp[pos][small][prev];
        
        int maxDigit = small ? 1 : v[pos];
        int ans = 0;
        for(int i=0; i<=maxDigit; i++) {
            int nSmall = small || i < maxDigit;
            if(prev != 1 || i != 1) {
                ans += solve(pos+1, nSmall, i);
            }
        }
        return dp[pos][small][prev] = ans;
    }
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        while(n > 0) {
            v.push_back(n%2);
            n = n/2;
        }        
        reverse(v.begin(), v.end());
        return solve(0, 0, 0);
    }
};