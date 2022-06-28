class Solution {
public:
    bool solve(string &n1, string &n2, string s, bool check) {
        if(s.empty() && check) return true;
        string n3 = to_string(0LL + stoll(n1) + stoll(n2));
        int len = min(s.size(), n3.size());
        if(s.substr(0, len) == n3) {
            return solve(n2, n3, s.substr(len), true);
        }
        return false;
    }
    bool isAdditiveNumber(string s) {
        int n = s.size();
        for(int i=1; i<n-1; i++) {
            string n1 = s.substr(0, i);
            if(n1.size() > 1 && n1[0] == '0') break;
            for(int j=i+1; j<n; j++) {
                string n2 = s.substr(i, j-i);
                if(n2.size() > 1 && n2[0] == '0') break;
                bool check = solve(n1, n2, s.substr(j), false);
                if(check) return true;
            }
        }
        return false;
    }
};