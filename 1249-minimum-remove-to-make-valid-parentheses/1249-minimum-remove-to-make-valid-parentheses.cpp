class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0, n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') {
                if(cnt > 0) cnt--;
                else s[i] = '*';
            }
        }
        cnt = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == ')') cnt++;
            else if(s[i] == '(') {
                if(cnt > 0) cnt--;
                else s[i] = '*';
            }
        }
        string ans;
        for(int i=0; i<n; i++) {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }
};