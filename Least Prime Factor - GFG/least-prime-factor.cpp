// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int>spf(n+1, 0);
        spf[0] = spf[1] = 1;
        for(int i=2; i<=n; i++) {
            if(spf[i] == 0) {
                spf[i] = i;
                for(int j=i*i; j<=n; j+=i) {
                    if(spf[j] == 0) spf[j] = i;
                }
            }
        }
        return spf;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}
  // } Driver Code Ends