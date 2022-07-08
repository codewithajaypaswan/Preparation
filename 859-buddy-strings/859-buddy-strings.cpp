class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(goal.size() != s.size()) return false;
        if(s == goal) {
            sort(s.begin(), s.end());
            for(int i=0; i<s.size()-1; i++) {
                if(s[i] == s[i+1]) return true;
            }
            return false;
        }
        int x = -1;
        for(int i=0; i<s.size(); i++) {
            if(s[i] != goal[i]) {
                if(x == -1) {
                    x = i;
                }
                else {
                    swap(s[x], s[i]);
                    return s == goal;
                }
            }
        }
        return false;
    }
};