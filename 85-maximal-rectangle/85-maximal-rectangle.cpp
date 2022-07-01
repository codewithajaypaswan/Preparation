class Solution {
public:
    int largetRect(vector<int>&v) {
        int n = v.size();
        vector<int>prev_smaller(n), next_smaller(n);
        stack<int>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            if(st.empty()) prev_smaller[i] = -1;
            else prev_smaller[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            if(st.empty()) next_smaller[i] = n;
            else next_smaller[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int len = next_smaller[i] - prev_smaller[i] - 1;
            ans = max(ans, len*v[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int>v(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '0') v[j] = 0;
                else v[j]++;
            }
            ans = max(ans, largetRect(v));
        }
        return ans;
    }
};