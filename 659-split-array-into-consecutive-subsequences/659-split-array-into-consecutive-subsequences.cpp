class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp, freq;
        for(int x:nums) {
            freq[x]++;
        }
        for(int x:nums) {
            if(freq[x] == 0) continue;
            else if(mp[x] > 0) {
                freq[x]--;
                mp[x]--;
                mp[x+1]++;
            }
            else if(freq[x+1] && freq[x+2]) {
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;
                mp[x+3]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};