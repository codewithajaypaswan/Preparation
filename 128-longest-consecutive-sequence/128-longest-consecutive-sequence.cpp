class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(st.find(nums[i] - 1) != st.end()) continue;
            int len = 1;
            while(st.find(nums[i] + len) != st.end()) len++;
            ans = max(ans, len);
        }
        return ans;
    }
};