class Solution {
public:
    string breakPalindrome(string s) {
        int i = 0, j = s.size()-1;
        if(s.size() == 1) return "";
        while(i < j) {
            if(s[i] == s[j] && s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
            i++; j--;
        }
        s[s.size()-1] = 'b';
        return s;
    }
};