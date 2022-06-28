class Solution {
public:
    int singleNumber(vector<int>& A) {
        int one = 0, two = 0;
        for(int x:A) {
            one = (one ^ x) & (~two);
            two = (two ^ x) & (~one);
        }
        return one;
    }
};