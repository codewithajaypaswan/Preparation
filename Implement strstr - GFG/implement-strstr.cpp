// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
vector<int>solve(string s) {
    int n = s.size();
    vector<int>lps(n);
    int i = 1, j = 0;
    while(i < n) {
        if(s[i] == s[j]) {
            lps[i++] = ++j;
        }
        else if(j == 0) i++;
        else j = lps[j-1];
    }
    return lps;
}
int strstr(string s, string x)
{
     vector<int>lps = solve(x);
     int i = 0, j = 0;
     while(i < s.size() && j < x.size()) {
         if(s[i] == x[j]) {
             i++; j++;
             if(j == x.size()) return i - j;
         }
         else if(j == 0) i++;
         else j = lps[j-1];
     }
     return -1;
}