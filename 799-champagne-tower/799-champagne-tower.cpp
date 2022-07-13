class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(105, vector<double>(105, 0.0));
        dp[0][0] = poured;
        for(int i=0; i<=query_row; i++) {
            for(int j=0; j<=query_glass; j++) {
                double left = max(dp[i][j] - 1, 0.0);
                if(left > 0) {
                    dp[i+1][j] += left/2;
                    dp[i+1][j+1] += left/2;
                }
            }
        }
        return min(dp[query_row][query_glass], 1.0);
    }
};