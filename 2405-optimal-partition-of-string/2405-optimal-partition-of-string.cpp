class Solution {
public:
    int checkBit(int flag, int n) {
        return (flag&(1<<n));
    }
    void setBit(int &flag, int n) {
        flag |= (1<<n);
    }
    int partitionString(string s) {
        int n = s.size(), ans = 1, flag = 0;
        for(int i=0; i<n; i++) {
            int ch = s[i] - 'a';
            if(checkBit(flag, ch)) {
                flag = 0;
                ans++;
            }
            setBit(flag, ch);
        }
        return ans;
    }
};