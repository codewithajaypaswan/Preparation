class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp, window;
        for(char c:t) {
            mp[c]++;
        }
        string ans = "";
        for(int start = 0, end = 0, count = 0, minL = INT_MAX; end < s.size(); end++) {
            char c = s[end];
            window[c]++;
            if(mp.find(c) != mp.end()) {
                if(mp[c] >= window[c]) count++;
            }
            if(count >= t.size()) {
                while(mp.find(s[start]) == mp.end() || window[s[start]] > mp[s[start]]) {
                    window[s[start]]--;
                    start++;
                }
                if(end - start + 1 < minL) {
                    minL = end - start + 1;
                    ans = s.substr(start, minL);
                }
            }
        }
        return ans;
    }
};