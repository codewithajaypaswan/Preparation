class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>ans;
        int mx = INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] > mx) {
                    mx = mat[i][j];
                    ans = {i, j};
                }
            }
        }
        return ans;
    }
};