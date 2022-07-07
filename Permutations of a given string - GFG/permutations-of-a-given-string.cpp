// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>ans;
	    void solve(string s, int cur) {
	        if(cur >= s.size()) {
	            ans.push_back(s);
	            return;
	        }
	        for(int i=cur; i<s.size(); i++) {
	            if(i > cur && s[i] == s[cur]) continue;
	            swap(s[i], s[cur]);
	            solve(s, cur+1);
	           // swap(s[i], s[cur]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    ans.clear();
		    sort(S.begin(), S.end());
		    solve(S, 0);
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends