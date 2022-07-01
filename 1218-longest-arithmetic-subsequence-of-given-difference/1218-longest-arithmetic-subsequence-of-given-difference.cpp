class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(int x:arr) {
            if(mp.count(x - dif)) {
                mp[x] = max(mp[x], mp[x - dif] + 1);
            }
            else {
                mp[x] = 1;
            }
            ans = max(ans, mp[x]);
        }
        return ans;
    }
};