class Solution {
public:
    string baseNeg2(int n) {
        string ans = "";
        while(n) {
            ans += to_string(n&1);
            n = -(n>>1);
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};