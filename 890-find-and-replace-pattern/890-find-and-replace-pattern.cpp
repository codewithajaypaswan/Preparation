class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        string s = normalize(pattern);
        for(string w:words) {
            if(normalize(w) == s) {
                ans.push_back(w);
            }
        }
        return ans;
    }
    string normalize(string s) {
        string str = "";
        unordered_map<char, char>mp;
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i]) != mp.end()) {
                str += mp[s[i]];
            }
            else {
                mp[s[i]] = (cnt + '0');
                str += (cnt + '0');
                cnt++;
            }
        }
        return str;
    }
};