class Solution {
public:
    bool ispal(string s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int>mp;
        int pal = 0;
        for(string s:words) {
            string temp = s;
            reverse(temp.begin(), temp.end());
            if(mp[temp] > 0) {
                if(ispal(temp, 0, temp.size()-1)) pal--;
                ans += 4;
                mp[temp]--;
                continue;
            }
            if(ispal(s, 0, s.size()-1)) {
                pal++;
            }
            mp[s]++;
            
        }
        if(pal) ans += 2;
        return ans;
    }
};
