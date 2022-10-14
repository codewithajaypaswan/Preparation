class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos, neg;
        for(int x:nums) {
            if(x < 0) neg.push_back(x);
            else pos.push_back(x);
        }
        for(int i = 0, idxNeg = 0, idxPos = 0; i<nums.size(); i++) {
            if(i%2 == 0) {
                nums[i] = pos[idxPos++];
            }
            else {
                nums[i] = neg[idxNeg++];
            }
        }
        return nums;
    }
};