class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>arr;
        for(int i=0; i<n; i++) {
            arr.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        vector<int>dp(n, 0); // dp[i] : maximum profit at the ith index
        dp[0] = arr[0][2];
        for(int i=1; i<n; i++) {
            int last = -1, low = 0, high = i-1;
            while(low <= high) {
                int mid = low + (high - low)/2;
                if(arr[mid][0] <= arr[i][1]) {
                    last = mid;
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
            if(last != -1) arr[i][2] += dp[last];
            dp[i] = max(dp[i-1], arr[i][2]);
        }
        return dp[n-1];
    }
};