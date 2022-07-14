class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long n = nums.size(), ans = INT_MAX;
        long sum = 0;
        deque<pair<long,long>>dq;
        for(long i=0; i<n; i++) {
            sum += nums[i];
            if(sum >= k) {
                ans = min(ans, i+1);
            }
            while(!dq.empty() && sum - dq.front().second >= k) {
                ans = min(ans, i - dq.front().first);
                dq.pop_front();
            }
            while(!dq.empty() && sum <= dq.back().second) {
                dq.pop_back();
            }
            dq.push_back({i, sum});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};