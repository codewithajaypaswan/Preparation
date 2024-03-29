class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n < 0 || n%4 != 0) return false;
        while(n > 0) {
            return isPowerOfFour(n/4);
        }
        return false;
    }
};