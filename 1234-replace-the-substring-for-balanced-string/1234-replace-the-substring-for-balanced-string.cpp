class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int>mp;
        for(char c:s) {
            mp[c]++;
        }
        int k = s.size()/4, ans = 1e9;
        for(int high = 0, low = 0; high < s.size(); high++) {
            mp[s[high]]--;
            while(low <= high + 1 && mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k) {
                ans = min(ans, high - low + 1);
                mp[s[low++]]++;
            }
        }
        return ans;
    }
};