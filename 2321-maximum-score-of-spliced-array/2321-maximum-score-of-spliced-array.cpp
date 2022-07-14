class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0, n = nums1.size();
        for(int i=0; i<n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        int mx1 = 0, mx2 = 0, res1 = 0, res2 = 0;
        for(int i=0; i<n; i++) {
            mx1 += nums2[i] - nums1[i];
            mx2 += nums1[i] - nums2[i];
            
            if(mx1 < 0) mx1 = 0;
            if(mx2 < 0) mx2 = 0;
            
            res1 = max(res1, mx1);
            res2 = max(res2, mx2);
        }
        return max(sum1 + res1, sum2 + res2);
    }
};