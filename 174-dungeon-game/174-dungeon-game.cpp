class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 1e9));
        dp[n][m-1] = dp[n-1][m] = 1;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int move = min(dp[i+1][j], dp[i][j+1]) - mat[i][j];
                dp[i][j] = move <= 0 ? 1 : move;
            }
        }
        return dp[0][0];
    }
};