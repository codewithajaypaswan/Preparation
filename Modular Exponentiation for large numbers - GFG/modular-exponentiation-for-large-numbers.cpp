// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    #define ll long long int
	    ll solve(ll x, ll n, ll M) {
	        if(n == 1) return x;
	        if(n&1) return (x * solve(x, n-1, M))%M;
	        else return solve((x*x)%M, n/2, M)%M;
	    }
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    return solve(x, n, M);
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends