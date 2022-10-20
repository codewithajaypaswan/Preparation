class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int k=0; k<2*n; k++) {
            int i = k%n;
            while(!st.empty() && nums[st.top()] < nums[i]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};