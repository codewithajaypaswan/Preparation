class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int>temp = nums;
        int n = nums.size(), ans = nums[0];
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0], 0});
        for(int i=1; i<n; i++) {
            while(!pq.empty() && i - pq.top().second > k) pq.pop();
            temp[i] = max(temp[i], pq.top().first + nums[i]);
            ans = max(ans, temp[i]);
            pq.push({temp[i], i});
        }
        return ans;
    }
};