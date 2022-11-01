class Solution {
public:
    int dfs(vector<vector<int>>&grid, int row, int col) {
        int n = grid.size(), m = grid[0].size();
        if(row == n) return col;
        if(n < 0 || m < 0 || row >= n || col >= m) return -1;
        if(grid[row][col] == 1) {
            if(col+1 < m && grid[row][col+1] == 1)
                 return dfs(grid, row+1, col+1);
        }
        if(grid[row][col] == -1) {
            if(col-1 >= 0 && grid[row][col-1] == -1) return dfs(grid, row+1, col-1);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int>ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = dfs(grid, 0, i);
        }
        return ans;
    }
};