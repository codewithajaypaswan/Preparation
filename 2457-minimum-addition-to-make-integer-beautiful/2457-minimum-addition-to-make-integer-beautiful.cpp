class Solution {
public:
    int digitSum(long long n) {
        int ans = 0;
        while(n > 0) {
            ans += n%10;
            n = n/10;
        }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long org = n, base = 1;
        while(n > 0 && digitSum(n) > target) {
            n = n/10 + 1;
            base = base * 10;
        }
        return n*base - org;
    }
};