class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26, 0), seen(26, 0);
        for(char c:s) {
            freq[c - 'a']++;
        }
        stack<char>st;
        for(char c:s) {
            freq[c - 'a']--;
            if(seen[c - 'a']) continue;
            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = 0;
                st.pop();
            }
            seen[c - 'a'] = 1;
            st.push(c);
        }
        string ans;
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};