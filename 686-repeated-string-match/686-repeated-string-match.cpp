class Solution {
public:
    vector<int>find(string &s) {
        int n = s.size();
        vector<int>lps(n);
        int i = 1, j = 0;
        while(i < n) {
            if(s[i] == s[j]) lps[i++] = ++j;
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return lps;
    }
    int repeatedStringMatch(string str, string pattern) {
        vector<int>lps = find(pattern);
        int i = 0, j = 0;
        int n = str.size(), m = pattern.size();
        while(i<n){
            if(j<m && str[(i+j)%n]==pattern[j]){                 //this is to find in the 'a' string after in a cyclic manner --->after crossing the last index the '%a.size()' takes us back to the first index.
                ++j;
                continue;
            }
            if(j==m)return (i+j-1)/str.size()+1;                  //formula for counting the cyclic repeatation--->answer
            else j=lps[j];                                                        //if the chars don't match then we just take the previous lcs value
            i++;
        }
        return -1;
    }
};