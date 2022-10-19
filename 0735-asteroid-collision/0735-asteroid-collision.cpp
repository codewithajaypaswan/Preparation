class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        for(int x:arr) {
            bool destroy = false;
            while(!st.empty() && x < 0 && st.top() > 0 && !destroy) {
                if(abs(x) < st.top()) {
                    destroy = true;
                }
                else if(abs(x) > st.top()) {
                    st.pop();
                }
                else {
                    destroy = true;
                    st.pop();
                }
            }
            if(!destroy) st.push(x);
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};