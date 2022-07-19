class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(char t:tasks) {
            mp[t]++;
        }
        stack<int>st;
        for(auto it:mp) {
            st.push(it.second);
        }
        int ans = 0;
        while(!st.empty()) {
            vector<int>temp;
            int time = 0;
            while(!st.empty()) {
                int x = st.top(); st.pop();
                temp.push_back(x-1);
                time++;
            }
            for(int i=0; i<temp.size(); i++) {
                if(temp[i]) st.push(temp[i]);
            }
            ans += st.empty() ? time : n+1;
        }
        int len = tasks.size();
        ans = max(ans, len);
        return ans;
    }
};