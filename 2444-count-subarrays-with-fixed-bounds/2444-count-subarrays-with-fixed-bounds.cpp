class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        bool seenMin = false, seenMax = false;
        long minStart = 0, maxStart = 0, start = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == minK) {
                minStart = i;
                seenMin = true;
            }
            if(nums[i] == maxK) {
                maxStart = i;
                seenMax = true;
            }
            if(nums[i] > maxK || nums[i] < minK) {
                minStart = maxStart = 0;
                seenMin = false; seenMax = false;
                start = i+1;
            }
            if(seenMax && seenMin) {
                ans += min(minStart, maxStart) - start + 1;
            }
        }
        return ans;
    }
};