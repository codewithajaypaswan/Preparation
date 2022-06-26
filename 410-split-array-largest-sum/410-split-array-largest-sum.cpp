class Solution {
public:
    bool valid(vector<int>&nums, int mid, int m) {
        int cnt = 1, sum = 0;
        for(int x:nums) {
            if(sum + x > mid) {
                cnt++;
                sum = x;
            }
            else {
                sum += x;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 0;
        for(int x:nums) {
            low = max(low, x);
            high += x;
        }
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(valid(nums, mid, m)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};