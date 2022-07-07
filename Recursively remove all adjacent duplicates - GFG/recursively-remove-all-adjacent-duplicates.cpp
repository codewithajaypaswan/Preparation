// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        int n = s.size();
        int i = 0, last = 0;
        string ans = "";
        while(i < n) {
            int j = i+1, flag = 0;
            while(j < n && s[i] == s[j]) {
                j++;
                flag = 1, last = 1;
            }
            if(flag) {
                i = j;
            }
            else {
                ans += s[i];
                i++;
            }
        }
        if(last) return rremove(ans);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends