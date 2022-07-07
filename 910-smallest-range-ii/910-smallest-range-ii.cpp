class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int smallest = nums[0] + k, largest = nums[n-1] - k;
        int ans = nums[n-1] - nums[0];
        for(int i=0; i<n-1; i++) {
            int sm = min(smallest, nums[i+1] - k);
            int lg = max(largest, nums[i] + k);
            ans = min(ans, lg - sm);
        }
        return ans;
    }
};