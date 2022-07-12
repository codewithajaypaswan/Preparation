// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int fingerCount(int N)
    {
        if(N <= 5) return N;
        if(N%8 == 1) return 1;
        if(N%8 == 0 || N%8 == 2) return 2;
        if(N%8 == 3 || N%8 == 7) return 3;
        if(N%8 == 4 || N%8 == 6) return 4;
        else return 5;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
      
        Solution ob;
        int ans  = ob.fingerCount(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends