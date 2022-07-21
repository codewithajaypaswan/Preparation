class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size()-2;
        while(i >= 0 && s[i] >= s[i+1]) i--;
        if(i >= 0) {
            int j = s.size()-1;
            while(j >= 0 && s[j] <= s[i]) j--;
            swap(s[i], s[j]);
        }
        reverse(s.begin()+i+1, s.end());
        // cout<<s<<endl;
        long x = stoll(s);
        return (x > INT_MAX || x <= n) ? -1 : x; 
    }
};