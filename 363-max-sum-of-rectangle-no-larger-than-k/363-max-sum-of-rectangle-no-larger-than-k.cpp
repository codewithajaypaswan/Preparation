class Solution {
public:
    int findMax(vector<int>&mat, int k) {
        set<int>st;
        st.insert(0);
        int prefixSum = 0, res = INT_MIN;
        for(int i=0; i<mat.size(); i++) {
            prefixSum += mat[i];
            // find the element in the set which is larger than or equal to (prefixSum - k) in the set
            auto it = st.lower_bound(prefixSum - k);
            if(it != st.end()) {
                res = max(res, prefixSum - *it);
            }
            st.insert(prefixSum);
        }
        return res;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            vector<int>colSum(m, 0);
            for(int r=i; r<n; r++) {
                for(int c=0; c<m; c++)
                    colSum[c] += matrix[r][c];
                ans = max(ans, findMax(colSum, k));
            }
        }
        return ans;
    }
};