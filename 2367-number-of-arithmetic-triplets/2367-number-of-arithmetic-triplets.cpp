class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int, int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(mp[nums[i] - diff] && mp[nums[i] + diff]) {
                cnt++;
            }
        }
        return cnt;
    }
};