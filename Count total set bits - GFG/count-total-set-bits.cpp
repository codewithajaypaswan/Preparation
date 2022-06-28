// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n <= 1) return n;
        int x = lastSetBit(n);
        return (1<<(x-1))*x + (n - (1<<x) + 1) + countSetBits(n - (1<<x));
    }
    int lastSetBit(int n) {
        for(int i=31; i>=0; i--) {
            if(n&(1<<i)) return i;
        }
        return 0;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends