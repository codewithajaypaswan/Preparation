class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long>dp(n+1);
        dp[0] = startFuel;
        for(int i=0; i<n; i++) {
            for(int refil = i; refil >= 0; refil--) {
                if(dp[refil] >= stations[i][0]) {
                    dp[refil+1] = max(dp[refil+1], dp[refil] + stations[i][1]);
                }
            }
        }
        for(int i=0; i<=n; i++) {
            if(dp[i] >= target) return i;
        }
        return -1;
    }
};