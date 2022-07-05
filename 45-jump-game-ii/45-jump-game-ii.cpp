class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), maxJump = 0, ans = 0, mx = 0;
        for(int i=0; i<n; i++) {
            if(i > maxJump) {
                ans++;
                maxJump = mx;
            }
            mx = max(mx, nums[i]+i);
        }
        return ans;
    }
};