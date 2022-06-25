class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>res(2, -1);
        if(n == 0) return res;
        // find the left position
        int low = 0, high = n-1, ans = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target && (ans == -1 || mid < ans)) {
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        if(ans == -1) return res;
        res[0] = ans;
        low = ans;
        high = n-1;
        ans = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target && (ans == -1 || mid > ans)) {
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        res[1] = high;
        return res;
    }
};