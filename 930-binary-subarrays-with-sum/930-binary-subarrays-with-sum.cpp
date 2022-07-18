class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        unordered_map<int,int> mp;
        int prefSum = 0;
        mp[0] = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            prefSum += nums[i];
            if(mp[prefSum - goal])
            {
                count += mp[prefSum - goal];
            }
            mp[prefSum]++;
        }
        return count;
    }
};