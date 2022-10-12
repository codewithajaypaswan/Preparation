class Solution {
public:
    bool solve(string &s, string &t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        for(int i=0; i<m && j < n; i++) {
            if(t[i] == s[j]) j++;
        }
        return j == n;
    }
    bool isSubsequence(string s, string t) {
        return solve(s, t);
    }
};