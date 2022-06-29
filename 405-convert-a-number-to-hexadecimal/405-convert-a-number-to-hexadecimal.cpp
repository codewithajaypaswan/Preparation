class Solution {
public:
    string HEX = "0123456789abcdef";
    string toHex(int num) {
        if(num == 0) return "0";
        string ans;
        unsigned int n = num;
        while(n) {
            ans += HEX[n%16];
            n = n/16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};