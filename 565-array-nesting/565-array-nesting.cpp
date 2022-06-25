class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n, false);
        int ans = 1;
        // now our question reduces to find the longest cycle present in the array
        for(int x:nums) {
            int cnt = 0;
            while(vis[x] == false) {
                vis[x] = true;
                cnt++;
                x = nums[x];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};