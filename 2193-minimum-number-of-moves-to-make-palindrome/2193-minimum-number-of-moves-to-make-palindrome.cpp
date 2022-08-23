class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;
        while(s.size()) {
            int pos = s.find(s.back());
            if(pos == s.size()-1) {
                res += s.size()/2;
            }
            else {
                res += pos;
                s.erase(pos, 1);
            }
            s.pop_back();
        }
        return res;
    }
};