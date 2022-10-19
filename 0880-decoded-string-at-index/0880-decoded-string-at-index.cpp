class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0, n = s.size();
        for(char c:s) {
            if(c >= '0' && c <= '9') {
                len *= (c - '0');
            }
            else {
                len++;
            }
        }
        for(int i=n-1; i>=0; i--) {
            k = k%len;
            if(!isdigit(s[i]) && k == 0) {
                string ans = string(1, s[i]);
                return ans;
            }
            else if(isdigit(s[i])) {
                len = len/(s[i] - '0');
            }
            else {
                len--;
            }
        }
        return "";
    }
};