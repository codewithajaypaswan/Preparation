class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0, ans = 0;
        for(int i=0; i<s.size(); i++) {
            cnt += s[i] == '0' ? 1 : 0;
            if(s[i] == '1' && cnt > 0) {
                ans = max(ans + 1, cnt);
            }
        }
        return ans;
    }
};