class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans(102, 0);
        int n = nums.size();
        for(int i=0; i<n; i++) {
            ans[nums[i]+1]++;
        }
        for(int i=1; i<=100; i++) {
            ans[i] += ans[i-1];
        }
        for(int i=0; i<n; i++) {
            nums[i] = ans[nums[i]];
        }
        return nums;
    }
};