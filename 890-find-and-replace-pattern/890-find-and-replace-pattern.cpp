class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        string p = normalize(pattern);
        for(string s:words) {
            if(normalize(s) == p) {
                ans.push_back(s);
            }
        }
        return ans;
    }
    string normalize(string &s) {
        unordered_map<char, char>mp;
        char ch = 'a';
        for(char c:s) {
            if(mp.find(c) == mp.end()) mp[c] = ch++;
        }
        string res = "";
        for(char c:s) {
            res += mp[c];
        }
        return res;
    }
};