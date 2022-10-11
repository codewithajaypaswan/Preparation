class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int i = 0, j = n-1, idx = n-1;
        while(i <= j) {
            if(abs(nums[i]) > abs(nums[j])) {
                ans[idx--] = nums[i]*nums[i];
                i++;
            }
            else {
                ans[idx--] = nums[j]*nums[j];
                j--;
            }
        }
        return ans;
    }
};