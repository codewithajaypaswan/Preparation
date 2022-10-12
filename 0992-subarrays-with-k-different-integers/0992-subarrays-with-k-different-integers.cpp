class Solution {
public:
    int atMost(vector<int>&nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int,int>mp;
        for(int high = 0, low = 0, cnt = 0; high < n; high++) {
            cnt += mp[nums[high]] == 0 ? 1 : 0;
            mp[nums[high]]++;
            while(cnt > k && low < n) {
                mp[nums[low]]--;
                cnt -= mp[nums[low]] == 0 ? 1 : 0;
                low++;
            }
            ans += (high - low + 1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};