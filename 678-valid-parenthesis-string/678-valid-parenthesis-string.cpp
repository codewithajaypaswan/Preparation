class Solution {
public:
    bool checkValidString(string s) {
        vector<int>left, star;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '*') star.push_back(i);
            else if(s[i] == '(') left.push_back(i);
            else {
                if(!left.empty()) left.pop_back();
                else if(!star.empty()) star.pop_back();
                else return false;
            }
        }
        while(left.size() && star.size()) {
            if(left.back() < star.back()) {
                left.pop_back();
                star.pop_back();
            }
            else {
                return false;
            }
        }
        return !left.size();
    }
};