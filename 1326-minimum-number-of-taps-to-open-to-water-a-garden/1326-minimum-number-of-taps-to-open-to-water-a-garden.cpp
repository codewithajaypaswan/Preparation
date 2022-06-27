class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
			int start = max(i - ranges[i], 0);
			int end = min(i + ranges[i], n);
			for (int j = start+1; j <= end; j++) {
				dp[j] = min(dp[j], dp[start] + 1);
			}
		}

		return dp[n] == 1e9 ? -1 : dp[n];
    }
};