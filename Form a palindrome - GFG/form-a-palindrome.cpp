// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string &s, vector<vector<int>>&dp, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) {
            return dp[i][j] = solve(s, dp, i+1, j-1);
        }
        return dp[i][j] = 1 + min(solve(s, dp, i+1, j), solve(s, dp, i, j-1));
    }
    int countMin(string str){
        int n = str.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(str, dp, 0, n-1);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends