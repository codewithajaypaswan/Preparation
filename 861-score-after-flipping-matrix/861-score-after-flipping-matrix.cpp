class Solution {
public:
    void toggleRow(vector<vector<int>>&grid, int r) {
        for(int i=0; i<grid[0].size(); i++) {
            if(grid[r][i] == 0) grid[r][i] = 1;
            else grid[r][i] = 0;
        }
    }
    void toggleCol(vector<vector<int>>&grid, int c) {
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][c] == 0) grid[i][c] = 1;
            else grid[i][c] = 0;
        }
    }
    
    int num(vector<int>&v) {
        int ans = 0;
        for(int i=0; i<v.size(); i++) {
            ans = ans * 2 + v[i];
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 0) toggleRow(grid, i);
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<grid[i].size(); j++) cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int j=1; j<m; j++) {
            int cnt0 = 0, cnt1 = 0;
            for(int i=0; i<n; i++) {
                if(grid[i][j] == 0) cnt0++;
                else cnt1++;
            }
            if(cnt0 > cnt1) toggleCol(grid, j);
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<grid[i].size(); j++) cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += num(grid[i]);
        }
        return ans;
    }
};