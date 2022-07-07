// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    int maxLen = -1, start = -1;
    int count(string &s, int low, int high) {
        while(low >= 0 && high < s.size() && s[low] == s[high]) {
            low--; high++;
        }
        low++; high--;
        if(high - low + 1 > maxLen) {
            maxLen = high - low + 1;
            start = low;
        }
    }
    string longestPalin (string s) {
        int n = s.size();
        for(int i=0; i<n-1; i++) {
            count(s, i, i);
            count(s, i, i+1);
        }
        if(start == -1) return s;
        return s.substr(start, maxLen);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends