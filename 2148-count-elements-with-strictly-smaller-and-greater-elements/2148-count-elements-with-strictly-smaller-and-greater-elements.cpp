class Solution {
public:
    int countElements(vector<int>& nums) {
        int sm = *min_element(nums.begin(), nums.end());
        int lg = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for(int x:nums) {
            if(x != sm && x != lg) cnt++;
        }
        return cnt;
    }
};