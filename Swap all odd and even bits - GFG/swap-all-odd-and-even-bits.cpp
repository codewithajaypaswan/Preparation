// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	int ans = 0;
    	for(int i=1; i<31; i+=2) {
    	    if(n&(1<<i)) {
    	        ans += (1<<(i-1));
    	    }
    	    if(n&(1<<(i-1))) {
    	        ans += (1<<(i));
    	    }
    	}
    	return ans;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends