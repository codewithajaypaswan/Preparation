class Solution {
public:
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
    int strStr(string s, string x) {
        string str = x + "*" + s;
         vector<int>lps = solve(str);
         for(int i=0; i<str.size(); i++) {
             if(lps[i] == x.size()) {
                 return i - 2 * x.size();
             }
         }
         return -1;
    }
};