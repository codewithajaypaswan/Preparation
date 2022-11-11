class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), ind = 0;
        for(int i=0; i<n; i++) {
            if(i == 0 || nums[i] != nums[i-1])
                nums[ind++] = nums[i];
        }
        return ind;
    }
};