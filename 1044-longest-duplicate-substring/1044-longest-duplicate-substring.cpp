class Solution {
public:
    #define ll long long
    ll mod = 1e9+7;
    string check(string &s, int len) {
        ll p = 31, curPower = 1, hash = 0;
        unordered_map<ll, vector<ll>> mp = unordered_map<ll, vector<ll>>();
        // first find the inital hash
        for(int i=len-1; i>=0; i--) {
            hash = (hash + ((curPower * (s[i] - 'a' + 1))%mod)%mod)%mod;
            if(i > 0) curPower = (curPower * p)%mod;
        }
        mp[hash] = vector<ll>(1, 0);
        // now slide the window and find hash in O(1)
        for(int i=len; i<s.size(); i++) {
            hash = (hash - ((curPower * (s[i-len] - 'a' + 1))%mod)%mod + mod)%mod; // remove the first
            hash = (hash * p)%mod; // increase the power by p for each number
            hash = (hash + (s[i] - 'a' + 1))%mod;
            if(mp.find(hash) == mp.end()) {
                mp[hash] = vector<ll>(1, i - len + 1);
            }
            else {
                for(auto it:mp[hash]) {
                    string str = s.substr(i - len + 1, len);
                    if(s.substr(it, len) == str) return str;
                }
                mp[hash].push_back(i - len + 1);
            }
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int low = 0, high = s.size();
        string ans = "";
        while(low <= high) {
            int mid = low + (high - low)/2;
            string str = check(s, mid);
            if(str.size() > 0) {
                ans = str;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};