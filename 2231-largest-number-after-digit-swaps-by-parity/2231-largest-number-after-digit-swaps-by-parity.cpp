class Solution {
public:
    int largestInteger(int num) {
        vector<int>even, odd;
        string s = to_string(num);
        while(num > 0) {
            int x = num%10;
            if(x%2 == 0) {
                even.push_back(x);
            }
            else {
                odd.push_back(x);
            }
            num = num/10;
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int ans = 0;
        int evenInd = even.size()-1, oddInd = odd.size()-1;
        for(int i=0; i<s.size(); i++) {
            int x = s[i] - '0';
            if(x%2 == 0) {
                ans = ans * 10 + even[evenInd--];
            }
            else {
                ans = ans * 10 + odd[oddInd--];
            }
        }
        return ans;
    }
};