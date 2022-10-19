class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char c:num) {
            while(!st.empty() && c < st.top() && k > 0) {
                k--;
                st.pop();
            }
            if(st.empty() && c == '0') continue;
            else st.push(c);
        }
        while(!st.empty() && k > 0) {
            st.pop(); k--;
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
        
    }
};