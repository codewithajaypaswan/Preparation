class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string o:operations) {
            if(o == "C") {
                st.pop();
            }
            else if(o == "D") {
                int x = st.top() * 2; st.push(x);
            }
            else if(o == "+") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y); st.push(x);
                st.push(x+y);
            }
            else {
                int x = stoi(o);
                st.push(x);
            }
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};