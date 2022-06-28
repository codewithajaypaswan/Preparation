class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(), ans = 0;
        vector<int>freq(26, 0);
        for(char c:s) freq[c - 'a']++;
        unordered_set<int>st;
        for(int x:freq) {
            if(x == 0) continue;
            if(st.find(x) == st.end()) st.insert(x);
            else {
                while(st.find(x) != st.end() && x > 0) {
                    x--;
                    ans++;
                }
                if(x) st.insert(x);
            }
            ans;
        }
        return ans;
    }
};