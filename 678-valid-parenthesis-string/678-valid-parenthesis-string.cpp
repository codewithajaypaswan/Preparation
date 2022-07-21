class Solution {
public:
    bool checkValidString(string s) {
        vector<int>left, star;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                left.push_back(i);
            }
            else if(s[i] == '*') star.push_back(i);
            else {
                if(left.size() > 0) left.pop_back();
                else if(star.size() > 0) star.pop_back();
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
        return left.empty();
    }
};