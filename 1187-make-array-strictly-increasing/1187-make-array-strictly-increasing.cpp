class Solution {
public:
    int dp[2005][2005];
    int solve(vector<int>&arr1, vector<int>&arr2, int i, int j, int prev) {
        if(i >= arr1.size()) return 0;
        int k = upper_bound(arr2.begin()+j, arr2.end(), prev) - arr2.begin();
        // there are two case
        // when prev < arr1[i] then we have two choices either replace this number or not replace this number
        // else we have to replace this number
        if(dp[i][k] != -1) return dp[i][k];
        int case1 = 1e6, case2 = 1e6;
        if(k < arr2.size())
        case1 = 1 + solve(arr1, arr2, i+1, k+1, arr2[k]);
        if(prev < arr1[i]) {
            case2 = solve(arr1, arr2, i+1, k, arr1[i]); 
        }
        return dp[i][k] = min(case1, case2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        memset(dp, -1, sizeof(dp));
        int ans =  solve(arr1, arr2, 0, 0, -1e9);  
        return ans == 1e6 ? -1 : ans;
    }
};