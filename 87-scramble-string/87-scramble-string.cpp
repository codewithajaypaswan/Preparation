class Solution {
public:
    unordered_map<string, bool>mp;
    int solve(string s1, string s2) {
        if(s1 == s2) return true;
        string key = s1 + ">" + s2;
        if(mp.find(key) != mp.end()) return mp[key];
        int n = s1.size();
        for(int i=1; i<n; i++) {
            bool swap = solve(s1.substr(0, i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0, n-i));
            bool notSwap = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(swap || notSwap) return mp[key] = true;
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};