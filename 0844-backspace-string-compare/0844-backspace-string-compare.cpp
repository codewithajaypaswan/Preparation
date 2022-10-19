class Solution {
public:
    string find(string &s) {
        string ans = "";
        for(char c:s) {
            if(c == '#') {
                if(ans.size()) ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string a, b;
        a = find(s);
        b = find(t);
        return a == b;
    }
};