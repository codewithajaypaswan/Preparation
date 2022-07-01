class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high = 0, sum = 0, mx = 0;
        for(int x:arr) {
            sum += x;
            high = max(high, x);
        }
        // if(sum <= target) return high;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int sum = solve(mid, arr);
            if(sum == target) return mid;
            if(sum < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        int choice1 = solve(low, arr);
        int choice2 = solve(low-1, arr);
        if(abs(target - choice1) < abs(target - choice2)) return low;
        return low-1;
    }
    int solve(int mid, vector<int>&arr) {
        int ans = 0;
        for(int x:arr) {
            ans += x > mid ? mid : x;
        }
        return ans;
    }
};