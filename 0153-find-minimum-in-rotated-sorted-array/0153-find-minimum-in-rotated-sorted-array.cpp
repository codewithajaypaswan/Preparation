class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, ans, n = nums.size();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] <= nums[n-1]) {
                ans = nums[mid];
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};