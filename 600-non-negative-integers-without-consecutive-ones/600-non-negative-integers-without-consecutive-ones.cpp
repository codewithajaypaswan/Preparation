class Solution {
public:
    int findIntegers(int n) {
        vector<int>fib(32, 0);
        fib[0] = 1;
        fib[1] = 2;
        for(int i=2; i<32; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        int prevBit = 0, ans = 0;
        for(int i=31; i>=0; i--) {
            if(n&(1<<i)) {
                ans += fib[i];
                if(prevBit) return ans;
                prevBit = 1;
            }
            else {
                prevBit = 0;
            }
        }
        return ans+1; // to include zero
    }
};