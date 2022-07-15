class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector<int>cnt(1e5+7, 0), freq(1e5+7, 0);
        int n = nums.size();
        for(int x:nums) {
            cnt[x]++;
            freq[cnt[x]]++;
        }
        for(int i=n-1; i>0; i--) {
            // without deleting this number
            if(cnt[nums[i]] * freq[cnt[nums[i]]] == i) return i+1;
            // with deleting this number
            freq[cnt[nums[i]]]--;
            cnt[nums[i]]--;
            if(cnt[nums[i-1]] * freq[cnt[nums[i-1]]] == i) return i+1;
        }
        return 1;
    }
};