class Solution {
public:
    int dp[15][2][2];
    int solve(string &s, vector<string>&digits, int ind, int bound, int started) {
        if(ind >= s.size()) return started == 1 ? 1 : 0;
        if(dp[ind][bound][started] != -1) return dp[ind][bound][started];
        int maxDigit = bound ? s[ind] - '0' : 9;
        int ans = 0;
        if(started == 0) {
            ans = solve(s, digits, ind+1, 0, 0);
            for(int i=0; i<digits.size(); i++) {
                int cur = stoi(digits[i]);
                if(cur > maxDigit) continue;
                ans += solve(s, digits, ind+1, bound & (cur == maxDigit), 1);
            }
        }
        else {
            for(int i=0; i<digits.size(); i++) {
                int cur = stoi(digits[i]);
                if(cur > maxDigit) continue;
                ans += solve(s, digits, ind+1, bound & (cur == maxDigit), started);
            }
        }
        return dp[ind][bound][started] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return solve(s, digits, 0, 1, 0);
    }
};