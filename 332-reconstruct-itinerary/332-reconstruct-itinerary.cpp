class Solution {
public:
    vector<string>ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>>adj;
        for(auto t:tickets) {
            adj[t[0]].insert(t[1]);
        }
        stack<string>st;
        st.push("JFK");
        while(!st.empty()) {
            string cur = st.top();
            if(adj[cur].size() == 0) {
                ans.push_back(cur);
                st.pop();
            }
            else {
                auto it = adj[cur].begin();
                st.push(*it);
                adj[cur].erase(it);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};