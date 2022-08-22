class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size(), ans = INT_MAX;
        for(int high = 0, low = 0, cnt = 0; high < n; high++) {
            if(s[high] == 'W') cnt++;
            if(high-low+1 == k) {
                ans = min(ans, cnt);
                if(s[low] == 'W') cnt--;
                low++;
            }
        }
        return ans;
    }
};