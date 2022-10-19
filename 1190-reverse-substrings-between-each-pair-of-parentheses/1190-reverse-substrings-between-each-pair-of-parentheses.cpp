class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans = "";
        for(char c:s) {
            if(c == '(') st.push(c);
            else if(c == ')') {
                string temp = "";
                while(!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(char c:temp) {
                    st.push(c);
                }
            }
            else {
                st.push(c);
            }
        }
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};