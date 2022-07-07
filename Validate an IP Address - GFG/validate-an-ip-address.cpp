// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            vector<string>res;
            int n = s.size();
            s.push_back('.');
            for(int i=0, start = 0; i<=n; i++) {
                if(s[i] == '.') {
                    if(i - start == 0) return false;
                    res.push_back(s.substr(start,i - start));
                    // cout<<res.back()<<endl;
                    start = i+1;
                }
            }
            // cout<<res.size()<<endl;
            if(res.size() != 4) return 0;
            for(string s:res) {
                // cout<<s<<endl;
                if(s[0] == '0' && s.size() != 1) return false;
                if(isalpha(s[0])) return false;
                int x = stoi(s);
                if(x < 0 || x > 255) return false; 
            }
            return true;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends