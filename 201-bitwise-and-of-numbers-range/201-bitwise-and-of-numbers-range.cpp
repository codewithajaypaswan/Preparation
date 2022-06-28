class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while(left != right && left > 0 && right > 0) {
            left = (left >> 1);
            right = (right >> 1);
            cnt++;
        }
        return left<<cnt;
    }
};