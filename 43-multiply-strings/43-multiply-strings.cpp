class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string s(n1 + n2, '0');
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                int v1 = num1[i] - '0';
                int v2 = num2[j] - '0';
                int val = v1 * v2 + (s[i+j+1] - '0');
                s[i+j+1] = (val%10) + '0';
                s[i+j] += val/10;
            }
        }
        for(int i=0; i<s.size(); i++) {
            if(s[i] != '0') return s.substr(i);
        }
        return "0";
    }
};