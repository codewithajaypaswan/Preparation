class Solution {
public:
    int findComplement(int num) {
        for(int i=31; i>=0; i--) {
            if((1<<i)&num) {
                num ^= (1<<i);
                i--;
                while(i >= 0) {
                    if((1<<i)&num) {
                        num ^= (1<<i);
                    }
                    else {
                        num |= (1<<i);
                    }
                    i--;
                }
                return num;
            }
        }
        return num;
    }
};