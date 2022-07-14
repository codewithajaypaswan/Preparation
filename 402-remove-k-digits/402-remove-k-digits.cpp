class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char c:num) {
            while(!st.empty() && c < st.top() && k > 0) {
                st.pop();
                k--;
            }
            if(c == '0' && st.empty()) continue;
            st.push(c);
        }
        while(k > 0 && !st.empty()) {
            st.pop(); 
            k--;
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};