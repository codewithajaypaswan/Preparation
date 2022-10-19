class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size(), bal = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') bal++;
            else {
                bal--;
                if(i > 0 && s[i-1] == '(') ans += (1<<bal);
            }
        }
        return ans;
    }
};