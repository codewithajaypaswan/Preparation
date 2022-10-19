class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int>pairs(n+1);
        stack<int>st;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                int j = st.top(); st.pop();
                pairs[j] = i;
                pairs[i] = j;
            }
        }
        string ans;
        for(int i=0, dir = 1; i < n && i >= 0; i+=dir) {
            if(s[i] == '(' || s[i] == ')') {
                dir = -dir;
                i = pairs[i];
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};