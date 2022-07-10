class Solution {
public:
    int make_palindrome(string &s, int i, int j) {
        int res = 0;
        while(i < j) {
            if(s[i] != s[j]) {
                res++;
            }
            i++; j--;
        }
        return res;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>>count(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                count[i][j] = make_palindrome(s, i, j);
            }
        }
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(s, k, dp, 0, count);
    }
    int solve(string &s, int k, vector<vector<int>>&dp, int cur, vector<vector<int>>&count) {
        if(cur >= s.size() && k == 0) return 0;
        if(cur >= s.size() || k == 0) return 1000;
        if(dp[cur][k] != -1) return dp[cur][k];
        int ans = 1000;
        for(int i=cur; i<s.size(); i++) {
            ans = min(ans, count[cur][i] + solve(s, k-1, dp, i+1, count));
        }
        return dp[cur][k] = ans;
    }
};