class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char,int>mp;
        for(int high = 0, low = 0; high < n; high++) {
            if(mp[s[high]] > 0) {
                mp.clear();
                ans++;
            }
            mp[s[high]]++;
           
        }
        return ans+1;
    }
};