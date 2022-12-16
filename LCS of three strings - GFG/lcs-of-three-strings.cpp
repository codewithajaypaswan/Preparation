//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int dp[25][25][25];
int solve(string &A, string &B, string &C, int i, int j, int k) {
    if(i == A.size() || j == B.size() || k == C.size()) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(A[i] == B[j] && B[j] == C[k]) {
        return dp[i][j][k] = 1 + solve(A, B, C, i+1, j+1, k+1);
    }
    
    return dp[i][j][k] = max({solve(A, B, C, i+1, j, k), solve(A, B, C, i, j+1, k), solve(A, B, C, i, j, k+1)});
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    memset(dp, -1, sizeof(dp));
    return solve(A, B, C, 0, 0, 0);
}