class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(!st.empty()){
                if(st.top() == '(' && c == ')') st.pop();
                else if(st.top() == '{' && c == '}') st.pop();
                else if(st.top() == '[' && c == ']') st.pop();
                else st.push(c);
            }
            else st.push(c);
        }
        return st.empty();
    }
};