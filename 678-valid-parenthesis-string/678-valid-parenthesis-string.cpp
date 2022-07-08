class Solution {
public:
    bool checkValidString(string s) {
        int cmax = 0, cmin = 0, ans = 0;
        for(char c:s) {
            if(c == '(') {
                cmax++; cmin++;
            }
            else if(c == ')') {
                cmax--; cmin--;
            }
            else {
                cmax++; cmin--;
            }
            if(cmax < 0) return false;
            cmin = max(0, cmin);
        }
        return cmin == 0;
    }
};