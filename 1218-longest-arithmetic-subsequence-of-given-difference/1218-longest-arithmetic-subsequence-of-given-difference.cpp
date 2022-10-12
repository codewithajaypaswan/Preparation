class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        unordered_map<int, int>mp;
        int n = arr.size(), ans = 0;
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i] - dif) != mp.end()) {
                mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - dif] + 1);
            }
            else {
                mp[arr[i]] = 1;
            }
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};