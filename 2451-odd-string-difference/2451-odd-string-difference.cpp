class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, int>mp1;
        unordered_map<string, string>mp2;
        for(string s:words) {
            string str = "";
            for(int i=1; i<s.size(); i++) {
                str += to_string(s[i] - s[i-1]) + "*";
            }
            mp2[str] = s;
            mp1[str]++;
        }
        for(auto it:mp1) {
            if(it.second == 1) return mp2[it.first];
        }
        return "";
    }
};