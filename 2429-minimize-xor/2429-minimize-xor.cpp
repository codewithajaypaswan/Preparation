class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt2 = 0, cnt1 = 0;
        for(int i=0; i<32; i++) {
            if(num2&(1<<i)) cnt2++;
            if(num1&(1<<i)) cnt1++;
        }
        int ans = 0;
        for(int i=31; i>=0; i--) {
            if(num1&(1<<i)) {
                if(cnt2 > 0) {
                    cnt2--;
                    cnt1--;
                    ans += (1<<i);
                }
                else {
                    cnt2--;
                }
            }
            else if(cnt1 == 0) break;
        }
        if(cnt2 > 0) {
            for(int i=0; i<32 && cnt2 > 0; i++) {
                if(!((1<<i)&num1)) {
                    ans += (1<<i);
                    cnt2--;
                }
            }
        }
        return ans;
    }
};