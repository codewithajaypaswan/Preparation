class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, sum = 0;
        for(int x:nums) {
            sum += x;
            mn = min(mn, x);
        }
        return sum - 1LL * mn * n;
    }
};