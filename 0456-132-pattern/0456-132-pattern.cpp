class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 132 --> 32 fix and the iterated over to find 1
        //{s1, s2, s3}
        //{s1 we have to find, s2 is in the stack , s3 is the last number}
        // example of monotone 
        stack<int>st;
        int s3 = INT_MIN, n = nums.size();
        for(int i=n-1; i>=0; i--) {
            if(nums[i] < s3) return true;
            while(!st.empty() && st.top() < nums[i]) {
                s3 = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};