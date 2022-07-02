class Solution {
public:
    int mod = 1e9+7;
    int solve(int n, vector<int>&v) {
        sort(v.begin(), v.end());
        int ans = max(v[0], n - v[v.size()-1]);
        for(int i=1; i<v.size(); i++) {
            ans = max(ans, v[i] - v[i-1]);
        }
        return ans;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (1LL * solve(h, horizontalCuts) * solve(w, verticalCuts))%mod;
    }
};