class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        deque<int>dq;
        vector<long long>pre(n+1, 0);
        for(int i=0; i<n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        for(int i=0; i<=n; i++) {
            while(!dq.empty() && pre[i] - pre[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && pre[i] <= pre[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};