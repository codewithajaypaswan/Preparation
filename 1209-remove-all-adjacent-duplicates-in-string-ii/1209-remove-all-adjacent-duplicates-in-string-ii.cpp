class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(char c:s) {
            if(!st.empty() && st.top().first == c) {
                st.top().second += 1;
                if(st.top().second == k) st.pop();
            }
            else {
                st.push({c , 1});
            }
        }
        string ans = "";
        while(!st.empty()) {
            auto it = st.top(); st.pop();
            while(it.second-- > 0) {
                ans += it.first;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};