class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& arr, int i, int j) {
        if(i == arr.size()-1 && j >=0 && j < arr[0].size()) return arr[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j)
                continue;
            int curr = arr[i][j] + solve(arr, i + 1, k);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size(), m = grid[0].size(), ans = INT_MAX;
        for(int i=0; i<m; i++) {
            ans = min(ans, solve(grid, 0, i));
        }
        return ans;
    }
};