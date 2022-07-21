class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char,int>mp;
        for(int high = 0, low = 0; high < n; high++) {
            if(mp.find(s[high]) != mp.end()) {
                low = max(low, mp[s[high]] + 1);
            }
            mp[s[high]] = high;
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};