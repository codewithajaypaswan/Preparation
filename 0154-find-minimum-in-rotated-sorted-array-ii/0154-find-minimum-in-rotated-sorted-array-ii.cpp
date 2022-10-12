class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0], low = 0, high = nums.size()-1, n = nums.size();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[n-1]) {
                ans = nums[mid];
                high = mid-1;
            }
            else if(nums[mid] > nums[n-1]) {
                low = mid+1;
            }
            else {
                ans = min(ans, nums[high]);
                high--;
            }
        }
        return ans;
    }
};