class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<=n-3; i++) {
            vector<int>temp;
            for(int j=0; j<=m-3; j++) {
                int res = INT_MIN;
                for(int row = 0; row < 3; row++) {
                    for(int col = 0; col < 3; col++) {
                        res = max(res, grid[i+row][j+col]);
                    }
                }
                temp.push_back(res);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};