class Solution {
public:
    long countZero(long n) {
        long p = 5, ans = 0;
        while(n/p > 0) {
            ans += n/p;
            p = p*5;
        }
        return ans;
    }
    int solve(int k) {
        long low = 0, high = 1e11;
        while(low <= high) {
            long mid = low + (high - low)/2;
            long cnt = countZero(mid);
            if(cnt > k) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
    int preimageSizeFZF(int k) {
        return solve(k) - solve(k-1);
    }
};