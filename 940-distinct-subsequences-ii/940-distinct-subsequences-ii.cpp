class Solution {
public:
    int distinctSubseqII(string s) {
        long n = s.size(), mod = 1e9+7, ans = 0, added = 0;
        vector<long>endWith(26, 0);
        for(int i=0; i<n; i++) {
            added = (ans - endWith[s[i] - 'a'] + 1)%mod;
            ans = (ans + added)%mod;
            endWith[s[i] - 'a'] = (endWith[s[i] - 'a']+added)%mod;
        }
        return (ans+mod)%mod;
    }
};