class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        for(int high = 0, low = 0, cnt = 0; high < s.size(); high++) {
            if(s[high] == 'a' || s[high] == 'e' || s[high] == 'i' || s[high] == 'o' || s[high] == 'u') cnt++;
            if(high - low + 1 == k) {
                ans = max(ans, cnt);
                if(s[low] == 'a' || s[low] == 'e' || s[low] == 'i' || s[low] == 'o' || s[low] == 'u') cnt--;
                low++;
            }
        }
        return ans;
    }
};