class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxXor = 0, n = nums.size(), ans = 0;
        for(int x:nums) maxXor |= x;
        for(int mask = 1; mask < (1<<n); mask++) {
            int curXor = 0;
            for(int i=0; i<n; i++) {
                if(mask&(1<<i)) curXor |= nums[i];
            }
            if(curXor == maxXor) ans++;
        }
        return ans;
    }
};