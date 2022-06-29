// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int solve(int N, vector<long long int>&dp) {
        if(N <= 1) return N;
        if(dp[N] != -1) return dp[N];
        long long int ans = N;
        for(long long int i=1; i<=N-3; i++) {
            ans = max(ans, 0LL + i * solve(N-1-i, dp));
        }
        return dp[N] = ans;
    }
    long long int optimalKeys(int N){
        vector<long long int>dp(N+1, -1);
        return solve(N, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends