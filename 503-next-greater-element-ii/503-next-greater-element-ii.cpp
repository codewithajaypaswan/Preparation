class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i=0; i<2*n; i++) {
            int k = i%n;
            while(!st.empty() && nums[st.top()] < nums[k]) {
                ans[st.top()] = nums[k];
                st.pop();
            }
            st.push(k);
        }
        return ans;
    }
};