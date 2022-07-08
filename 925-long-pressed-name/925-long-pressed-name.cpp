class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size(), i = 0, j = 0;
        while(i < n || j < m) {
            if(i < n && j < m && name[i] == typed[j]) {
                i++; j++;
            }
            else if(i > 0 && name[i-1] == typed[j]) j++;
            else return false;
        }
        return i == n && j == m;
    }
};