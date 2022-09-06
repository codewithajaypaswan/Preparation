class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(long long high = 0, low = 0, sum = 0; high < nums.size(); high++) {
            sum += nums[high];
            while(0LL + sum + k < 1LL * (high - low + 1) * nums[high]) {
                sum -= nums[low];
                low++;
            }
            ans = max(0LL + ans, high - low + 1);
        }
        return ans;
    }
};