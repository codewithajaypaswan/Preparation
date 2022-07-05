class Solution {
public:
    int longestSubsequence(string s, int k) {
        long sum = 0, j = 0, n = s.size(), ans = 0, check = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '0') ans++;
            else if(j < 31) {
                sum += (1<<j);
                if(k - sum >= 0) ans++;
            }
            j++;
        }
        return ans;
    }
};