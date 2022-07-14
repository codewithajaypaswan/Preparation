class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int x:asteroids) {
            bool destroy = false;
            while(!st.empty() && st.top() > 0 && x < 0 && !destroy) {
                if(st.top() > abs(x)) destroy = true;
                else if(st.top() < abs(x)) st.pop();
                else {
                    st.pop();
                    destroy = true;
                }
            }
            if(!destroy) st.push(x);
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};