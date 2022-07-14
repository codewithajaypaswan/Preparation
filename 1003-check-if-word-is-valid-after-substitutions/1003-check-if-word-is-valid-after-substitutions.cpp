class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s) {
            if(c == 'a' || c == 'b') st.push(c);
            else {
                if(st.size() >= 2) {
                    char b = st.top(); st.pop();
                    char a = st.top(); st.pop();
                    if(b == 'b' && a == 'a') continue;
                    st.push(a); st.push(b); st.push(c);
                }
                else {
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};