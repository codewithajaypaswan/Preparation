class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int>dif(n);
        for(int i=0; i<n; i++) {
            dif[i] = abs(nums1[i] - nums2[i]);
        }
        int M = *max_element(dif.begin(), dif.end());
        vector<int>bucket(M+1);
        for(int i=0; i<n; i++) {
            bucket[dif[i]]++;
        }
        int k = k1 + k2;
        for(int i=M; i>0; i--) {
            if(bucket[i]) {
                int minus = min(bucket[i], k);
                bucket[i] -= minus;
                bucket[i-1] += minus;
                k -= minus;
            }
        }
        long long ans = 0;
        for(int i=M; i>=0; i--) {
            if(bucket[i]) {
                ans += 1LL * bucket[i] * i * i;
            }
        }
        return ans;
    }
};