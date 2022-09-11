class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx = INT_MIN, num = INT_MAX;
        for(int x:nums) {
            if(x%2 != 0) continue;
            mp[x]++;
            mx = max(mx, mp[x]);
        }
        for(auto it:mp) {
            if(mx == it.second && it.first%2 == 0) {
                num = min(num, it.first);
            }
        }
        return num == INT_MAX ? -1 : num;
    }
};