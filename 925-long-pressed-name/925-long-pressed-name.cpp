class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = typed.size(), m = name.size(), j = 0;
        for(int i=0; i<n; i++) {
            if(j < m && typed[i] == name[j]) j++;
            else if(i > 0 && typed[i-1] == typed[i]) continue;
            else if(j == m) return false;
            else return false;
        }
        return j == name.size();
    }
};