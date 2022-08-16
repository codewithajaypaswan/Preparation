class Solution {
public:
    string shortestCompletingWord(string lc, vector<string>& words) {
        vector<int>freq1(26, 0);
        for(char c:lc) {
            if(isalpha(c)) {
                freq1[tolower(c) - 'a']++;
            }
        }
        string ans = "";
        int len = 1e9;
        for(string s:words) {
            vector<int>freq2(26, 0);
            for(char c:s) {
                if(isalpha(c)) {
                    freq2[tolower(c) - 'a']++;
                }
            }
            bool flag = true;
            for(int i=0; i<26; i++) {
                if(freq1[i] > freq2[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag && len > (int)s.size()) {
                ans = s;
                len = s.size();
            }
        }
        return ans;
    }
};