class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), ans = INT_MAX;
        vector<int>dp(n, 0);
        for(int i=1; i<n; i++) {
            dp[i] = i;
            for(int j=i-1; j>=0; j--) {
                if(check(strs, i, j)) {
                    dp[i] = min(dp[i], i-j-1 + dp[j]);
                }
            }
        }
        // return dp[n-1];
        for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        for(int i=0; i<n; i++) {
            // to delete from 0 to i we need to delete i char
            // to delete from i+1 to n we need to delete n-i-1 character
            ans = min(ans, dp[i] + n - i - 1);
        }
        return ans;
    }
    bool check(vector<string>&str, int i, int j) {
        for(string s:str) {
            if(s[i] < s[j]) return false;
        }
        return true;
    }
};