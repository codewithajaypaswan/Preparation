class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int mid = v[(n*m - 1)/2], ans = 0;
        for(int i=0; i<n*m; i++) {
            if((v[i] - mid)%x != 0) return -1;
            else ans += abs(v[i] - mid)/x;
        }
        return ans;
    }
};