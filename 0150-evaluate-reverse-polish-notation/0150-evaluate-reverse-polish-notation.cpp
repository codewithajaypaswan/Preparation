class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long>st;
        for(string s:tokens) {
            if(s == "*" || s == "+" || s == "/" || s == "-") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                if(s == "*") st.push(1LL * y*x);
                else if(s == "+") st.push(y+x);
                else if(s == "/") st.push(y/x);
                else st.push(y-x);
            }
            else {
                int x = stoi(s);
                st.push(x);
            }
        }
        return st.top();
    }
};