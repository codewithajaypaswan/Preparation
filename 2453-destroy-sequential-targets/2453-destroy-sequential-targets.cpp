class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>mp;
        int n = nums.size(), mxFreq = 0;
        for(int i=0; i<n; i++) {
            mp[nums[i]%space]++;
            mxFreq = max(mxFreq, mp[nums[i]%space]);
        }
        int ans = 1e9+5;
        for(int i=0; i<n; i++) {
            if(mp[nums[i]%space] == mxFreq) ans = min(ans, nums[i]);
        }
        return ans;
    }
};