// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<long long, long long>mp;
	    long long sum = 0, ans = 0;
	    mp[0] = -1;
	    for(int i=0; i<n; i++) {
	        sum = (sum + arr[i] + k)%k;
	        if(sum < 0) sum = (sum + k)%k;
	        if(mp.find(sum) != mp.end()) {
	            ans = max(ans, i - mp[sum]);
	        }
	        else if(mp.find(sum) == mp.end()) {
	            mp[sum] = i;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends