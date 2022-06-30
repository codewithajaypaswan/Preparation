class Solution {
public:
    int solve(vector<vector<int>>&mat, vector<vector<int>>&dp, int x, int y) {
        if(x == mat.size()-1 && y == mat[0].size() - 1) return mat[x][y] <= 0 ? abs(mat[x][y])+1 : 1;
        if(x == mat.size() || y == mat[0].size()) return 1e9;
        if(dp[x][y] != 1e9) return dp[x][y];
        int xMove = solve(mat, dp, x+1, y) - mat[x][y];
        int yMove = solve(mat, dp, x, y+1) - mat[x][y];
        int move = min(xMove, yMove);
        return dp[x][y] = move <= 0 ? 1 : move; 
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 1e9));
        return solve(mat, dp, 0, 0);
    }
};