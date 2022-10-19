class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0;
        for(char c:s) {
            if(c == '(') {
                open++;
                if(open > 1) ans += c;
            }
            else {
                if(open > 1) ans += c;
                open--;
            }
        }
        return ans;
    }
};