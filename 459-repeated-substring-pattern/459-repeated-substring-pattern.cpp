class Solution {
public:
    bool repeatedSubstringPattern(string s) {
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
        int len = lps[n-1];
        int left = n - len;
        return len && len % left == 0;
    }
};