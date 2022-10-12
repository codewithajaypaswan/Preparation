class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i=1; i<n; i++) {
            int mn = min({dp[p2]*2, dp[p3]*3, dp[p5]*5});
            if(mn == dp[p2]*2) p2++;
            if(mn == dp[p3]*3) p3++;
            if(mn == dp[p5]*5) p5++;
            dp[i] = mn;
        }
        return dp[n-1];
    }
};