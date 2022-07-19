class Solution {
public:
    const int mod = 1e9+7;
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        vector<int>power(n+1);
        power[0] = 1;
        for(int i=1; i<=n; i++) power[i] = (power[i-1] * 2)%mod;
        for(int i=0; i<n; i++) {
            ans = (0LL + ans + 1LL * (power[i] - power[n-1-i]) * nums[i])%mod;
        }
        return ans;
    }
};